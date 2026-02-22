local UEHelpers = require("UEHelpers")
local TAG = "[ML_ResourcePatcher] "

-- =========================
-- CONFIG / KILL-SWITCHES
-- =========================
local CFG = {
    -- Stabilster Weg: Runtime patchen (existierende Nodes)
    PATCH_RUNTIME_RESOURCES = true,       -- AResource (Resource_Stone_C, Resource_Fish_C, ...)
    PATCH_RUNTIME_DEPOSITS  = true,       -- ADepositDecal (Limit + bRichDeposit)
    PATCH_RUNTIME_NODES     = true,       -- ResourceNode/BP_ResourceNode: nur Rich-Flags (optional)

    -- Optional: für Generierung/Spawn (kann je nach UE4SS/Version instabil sein)
    PATCH_RESOURCE_SETTINGS = true,

    PASSES = 10,          -- wie viele Sekunden nach Map-Load patchen (Streaming)
    START_DELAY_PASSES = 2, -- erst ab Pass X anfangen (reduziert Race/CTD-Risiko)
    DEBUG_SAMPLES = 12,
}

-- =========================
-- Zielwerte (deine Vorgaben)
-- =========================
local TARGETS = {
    Salt   = { amount = 9999, rich = true  },
    Iron   = { amount = 9999, rich = true  },
    Clay   = { amount = 9999, rich = true  },
    Stone  = { amount = 9999, rich = true  },

    Fish      = { amount = 999,  rich = false },
    Berries   = { amount = 999,  rich = false },
    Deer      = { amount = 999,  rich = false }, -- Wild
    SmallGame = { amount = 999,  rich = false }, -- Wild
}

-- =========================
-- Helpers
-- =========================
local function safe_lower(s) return tostring(s or ""):lower() end

local function safe_call(obj, fn)
    if not obj or not obj.IsValid then return nil end
    local okValid, valid = pcall(function() return obj:IsValid() end)
    if not okValid or not valid then return nil end
    local ok, res = pcall(function() return fn(obj) end)
    if ok then return res end
    return nil
end

local function get_map_name(world)
    return tostring(
        safe_call(world, world.GetMapName)
        or safe_call(world, world.GetName)
        or safe_call(world, world.GetFullName)
        or ""
    )
end

local function is_gameplay_map(mapname)
    local m = safe_lower(mapname)
    return m ~= ""
        and not m:find("mainmenu", 1, true)
        and not m:find("frontend", 1, true)
end

local function is_level_instance(actor)
    local fn = tostring(actor and actor.GetFullName and actor:GetFullName() or "")
    return fn:find(":PersistentLevel", 1, true) ~= nil and fn:find("Default__", 1, true) == nil
end

local function try_get(obj, key)
    local ok, v = pcall(function() return obj[key] end)
    if ok then return v end
    return nil
end

local function try_set(obj, key, value)
    local ok = pcall(function() obj[key] = value end)
    return ok
end

local function to_num(v)
    local n = tonumber(v)
    if n ~= nil then return n end
    return nil
end

-- =========================
-- UE4SS TArray safe helpers
--  -> KEIN #arr und KEIN arr[i] als primärer Weg (kann CTD verursachen)
-- =========================
local function tarray_num(arr)
    if arr == nil then return nil end
    local ok, n = pcall(function() return arr:Num() end)
    if ok and type(n) == "number" then return n end
    ok, n = pcall(function() return arr:GetArrayNum() end)
    if ok and type(n) == "number" then return n end
    return nil
end

local function tarray_get(arr, idx0) -- idx0 = 0-based
    if arr == nil then return nil end
    local ok, v = pcall(function() return arr:Get(idx0) end)
    if ok then return v end
    return nil
end

-- =========================
-- Type detection
-- =========================

-- ENodeType enum (uint32): maps integer value -> canonical name
-- From ENodeType.h: None=0, Salt=1, Iron=2, Clay=3, Deer=4, Fish=5,
--                   Berries=6, Stone=7, Ladders=8, Mushrooms=9,
--                   SmallGame=10, Eel=11, Fertility=12
local ENODE_INT_TO_NAME = {
    [1] = "Salt", [2] = "Iron", [3] = "Clay", [4] = "Deer",
    [5] = "Fish", [6] = "Berries", [7] = "Stone", [10] = "SmallGame",
}

local function canonical_from_name(name)
    local s = safe_lower(tostring(name))
    -- try integer enum value first
    local n = tonumber(s)
    if n ~= nil then return ENODE_INT_TO_NAME[n] end
    -- substring matching for FName / class name strings
    if s:find("stone", 1, true) then return "Stone" end
    if s:find("clay", 1, true) then return "Clay" end
    if s:find("salt", 1, true) then return "Salt" end
    if s:find("iron", 1, true) or s:find("ore", 1, true) then return "Iron" end
    if s:find("fish", 1, true) then return "Fish" end
    if s:find("berries", 1, true) then return "Berries" end
    if s:find("deer", 1, true) then return "Deer" end
    if s:find("smallgame", 1, true) or s:find("small_game", 1, true) then return "SmallGame" end
    return nil
end

-- DepositDecal: depositType ist FName
local function canonical_from_depositType(depType)
    return canonical_from_name(depType)
end

-- =========================
-- Patch: AResource (Runtime)
-- =========================
local function patch_resource_actor(a)
    -- AResource: resType (FName), amt, capacity
    local t = canonical_from_name(try_get(a, "resType"))
    if not t then
        -- fallback: Classname
        local cls = safe_lower(a:GetClass():GetFullName())
        for k, _ in pairs(TARGETS) do
            if cls:find("resource_" .. safe_lower(k), 1, true) then
                t = k
                break
            end
        end
    end

    if not t or not TARGETS[t] then
        return false
    end

    local amt = TARGETS[t].amount
    local changed = false

    local curCap = to_num(try_get(a, "capacity"))
    if curCap ~= nil and curCap ~= amt then
        if try_set(a, "capacity", amt) then changed = true end
    end

    local curAmt = to_num(try_get(a, "amt"))
    if curAmt ~= nil and curAmt ~= amt then
        if try_set(a, "amt", amt) then changed = true end
    end

    return changed
end

-- =========================
-- Patch: ADepositDecal (Runtime)
-- =========================
local function patch_deposit_decal(a)
    local t = canonical_from_depositType(try_get(a, "depositType"))
    if not t or not TARGETS[t] then return false end

    local amt = TARGETS[t].amount
    local changed = false

    -- Limit patchen für ALLE Deposit-Typen (nicht nur Rich)
    local cur = to_num(try_get(a, "Limit"))
    if cur ~= nil and cur ~= amt then
        if try_set(a, "Limit", amt) then changed = true end
    end

    -- bRichDeposit nur für Mineables (Salt, Iron, Clay, Stone)
    if TARGETS[t].rich then
        local br = try_get(a, "bRichDeposit")
        if type(br) == "boolean" and br ~= true then
            if try_set(a, "bRichDeposit", true) then changed = true end
        end
    end

    return changed
end

-- =========================
-- Patch: ResourceNode rich flags (Runtime, optional)
--  -> NICHT an Struct/TArray rumfummeln; nur bool flags die existieren.
-- =========================
local function patch_node_rich_flags(node)
    local changed = false

    -- wir versuchen Type zu erraten (falls vorhanden)
    local guessed = nil
    for _, k in ipairs({"nodeType", "NodeType", "Type", "depositType", "DepositType"}) do
        local v = try_get(node, k)
        local c = canonical_from_name(v)
        if c then guessed = c break end
    end
    if not guessed then return false end
    if not TARGETS[guessed] or not TARGETS[guessed].rich then return false end

    for _, k in ipairs({"bRichNode", "bRichDeposit", "bIsRich", "bRich", "bRichResource"}) do
        local v = try_get(node, k)
        if type(v) == "boolean" and v ~= true then
            if try_set(node, k, true) then changed = true end
        end
    end

    return changed
end

-- =========================
-- Optional: ResourceSettings patch (nur wenn stabil)
-- =========================
local function find_resource_settings()
    local obj

    local ok = pcall(function() obj = FindFirstOf("ResourceSettings") end)
    if ok and obj and obj.IsValid and obj:IsValid() then return obj end

    ok = pcall(function() obj = FindFirstOf("UResourceSettings") end)
    if ok and obj and obj.IsValid and obj:IsValid() then return obj end

    ok = pcall(function() obj = StaticFindObject("/Script/ManorLords.Default__ResourceSettings") end)
    if ok and obj and obj.IsValid and obj:IsValid() then return obj end

    return nil
end

local function patch_resource_settings()
    local settings = find_resource_settings()
    if not settings then
        return false, "ResourceSettings not found"
    end

    local data = try_get(settings, "ResourceNodeData")
    if data == nil then
        return false, "ResourceNodeData missing"
    end

    local len = tarray_num(data)
    if not len or len <= 0 then
        return false, "ResourceNodeData length unknown"
    end

    local patched = 0

    for i0 = 0, len - 1 do
        local entry = tarray_get(data, i0)
        if entry ~= nil then
            local t = canonical_from_name(try_get(entry, "Type"))
            -- entry.Type ist ENodeType Enum; kann als int (1=Salt...) oder String kommen
            if t and TARGETS[t] then
                local props = try_get(entry, "Properties")
                if props ~= nil then
                    local amt = TARGETS[t].amount
                    local rich = TARGETS[t].rich

                    -- normale range
                    try_set(props, "MinResourceAmount", amt)
                    try_set(props, "MaxResourceAmount", amt)

                    -- rich range
                    try_set(props, "MinRichResourceAmount", amt)
                    try_set(props, "MaxRichResourceAmount", amt)

                    -- resourceCount: wie viele Clumps spawnen
                    try_set(props, "resourceCount", amt)

                    -- Mineables: underground deposits when rich
                    if rich then
                        try_set(props, "bIsLimitedResource", true)
                        try_set(props, "bUndergroundDepositsWhenRich", true)
                    end

                    -- Tiere: BreedingThreshold niedrig setzen -> schneller vermehren
                    if t == "Deer" or t == "SmallGame" then
                        try_set(props, "BreedingThreshold", 1)
                    end

                    patched = patched + 1
                end
            end
        end
    end

    return patched > 0, ("patched entries=%d/%d"):format(patched, len)
end

-- =========================
-- Main pass
-- =========================
local function patch_pass(debugLeft)
    local total = 0
    local patched = 0

    if CFG.PATCH_RUNTIME_RESOURCES then
        local resources = FindAllOf("Resource")
        if resources then
            for _, a in ipairs(resources) do
                if a and a.IsValid and a:IsValid() and is_level_instance(a) then
                    total = total + 1
                    if patch_resource_actor(a) then
                        patched = patched + 1
                        if debugLeft.value > 0 then
                            debugLeft.value = debugLeft.value - 1
                            print(TAG .. "patched Resource: " .. tostring(a:GetFullName()))
                        end
                    end
                end
            end
        end
    end

    if CFG.PATCH_RUNTIME_DEPOSITS then
        local deposits = FindAllOf("DepositDecal")
        if deposits then
            for _, a in ipairs(deposits) do
                if a and a.IsValid and a:IsValid() and is_level_instance(a) then
                    total = total + 1
                    if patch_deposit_decal(a) then
                        patched = patched + 1
                        if debugLeft.value > 0 then
                            debugLeft.value = debugLeft.value - 1
                            print(TAG .. "patched DepositDecal: " .. tostring(a:GetFullName()))
                        end
                    end
                end
            end
        end
    end

    if CFG.PATCH_RUNTIME_NODES then
        local nodes = FindAllOf("ResourceNode")
        if nodes then
            for _, n in ipairs(nodes) do
                if n and n.IsValid and n:IsValid() and is_level_instance(n) then
                    total = total + 1
                    if patch_node_rich_flags(n) then
                        patched = patched + 1
                        if debugLeft.value > 0 then
                            debugLeft.value = debugLeft.value - 1
                            print(TAG .. "patched ResourceNode (rich flag): " .. tostring(n:GetFullName()))
                        end
                    end
                end
            end
        end

        local bpnodes = FindAllOf("BP_ResourceNode_C")
        if bpnodes then
            for _, n in ipairs(bpnodes) do
                if n and n.IsValid and n:IsValid() and is_level_instance(n) then
                    total = total + 1
                    if patch_node_rich_flags(n) then
                        patched = patched + 1
                        if debugLeft.value > 0 then
                            debugLeft.value = debugLeft.value - 1
                            print(TAG .. "patched BP_ResourceNode (rich flag): " .. tostring(n:GetFullName()))
                        end
                    end
                end
            end
        end
    end

    return patched, total
end

-- =========================
-- Loop: pro Map ein paar Pässe
-- =========================
local tries = 0
local lastMap = ""
local didSettings = false

LoopAsync(1000, function()
    local world = UEHelpers.GetWorld()
    if not world or not world.IsValid or not world:IsValid() then
        return false
    end

    local mapname = get_map_name(world)
    if mapname ~= lastMap then
        lastMap = mapname
        tries = 0
        didSettings = false
        print(TAG .. "map: " .. mapname)
    end

    if not is_gameplay_map(mapname) then
        return false
    end

    tries = tries + 1

    if tries < CFG.START_DELAY_PASSES then
        return false
    end

    -- Settings einmal pro Map (optional)
    if CFG.PATCH_RESOURCE_SETTINGS and not didSettings then
        local ok, msg = patch_resource_settings()
        if ok then
            print(TAG .. "ResourceSettings patched: " .. msg)
        else
            print(TAG .. "ResourceSettings patch skipped: " .. tostring(msg))
        end
        didSettings = true
    end

    local dbg = { value = CFG.DEBUG_SAMPLES }
    local patched, total = patch_pass(dbg)

    print(("%s pass %d | patched=%d | scanned=%d"):format(TAG, tries, patched, total))

    if tries >= CFG.PASSES then
        print(TAG .. "done.")
        return true
    end

    return false
end)