local UEHelpers = require("UEHelpers")
local TAG = "[ML_ResourcePatcher] "

-- =========================
-- CONFIG / KILL-SWITCHES
-- =========================
local CFG = {
    -- Stabilster Weg: Runtime patchen (existierende Nodes)
    PATCH_RUNTIME_RESOURCES = true,       -- AResource (Resource_Stone_C, Resource_Fish_C, ...)
    PATCH_RUNTIME_DEPOSITS  = true,       -- ADepositDecal (Limit + bRichDeposit)
    PATCH_RUNTIME_NODES     = false,      -- DEAKTIVIERT: bRichNode etc. existieren NICHT auf AResourceNode (nur in SavedResourceNode)
    PATCH_RUNTIME_WILDLIFE  = true,       -- ASMUnit Wildlife: Breeding beschleunigen

    -- Fruchtbarkeit: Grid auf Maximum setzen (Getreide braucht keine Fruchtbarkeit)
    PATCH_FERTILITY         = true,
    FERTILITY_REFRESH_SEC   = 30,         -- Sekunden zwischen Fruchtbarkeits-Refreshes (0 = nur beim Map-Load)

    -- Optional: für Generierung/Spawn (kann je nach UE4SS/Version instabil sein)
    PATCH_RESOURCE_SETTINGS = true,

    PASSES = 10,          -- wie viele Sekunden nach Map-Load patchen (Streaming)
    START_DELAY_PASSES = 2, -- erst ab Pass X anfangen (reduziert Race/CTD-Risiko)
    DEBUG_SAMPLES = 12,
    DEBUG_UNMATCHED = true,  -- zeigt nicht erkannte Ressourcen/Deposits (Diagnose)
    DEBUG_FULL_SCAN = true,  -- listet ALLE gescannten Objekte mit Properties auf (einmal pro Map)
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
    Mushrooms = { amount = 999,  rich = false },
    -- Wildtiere: amount wirkt nur auf ResourceSettings (Spawn-Parameter),
    -- da Tiere ASMUnit-Aktoren sind, nicht AResource.
    Deer      = { amount = 999,  rich = false, wildlife = true },
    SmallGame = { amount = 999,  rich = false, wildlife = true },
}

-- EUnitRole -> canonical name (für Wildlife-Erkennung)
local WILDLIFE_ROLES = {
    [8]  = "Deer",      -- EUnitRole::Deer (enum index 8)
    [20] = "SmallGame", -- EUnitRole::Hare (enum index 20, = SmallGame im Spiel)
}

-- ECropType Enum: Getreide-Typen die normalerweise Fruchtbarkeit benötigen
-- Wheat=1, Flax=2, Barley=3, Rye=7 (aus ECropType.h)
-- FLinearColor hat 4 Kanäle (RGBA) — Mapping auf Getreidetypen intern im Spiel
local GRAIN_CROP_TYPES = { 1, 2, 3, 7 }  -- Wheat, Flax, Barley, Rye

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
    -- Method 1: :Get(idx) (UE4SS standard für UObject-Arrays)
    local ok, v = pcall(function() return arr:Get(idx0) end)
    if ok and v ~= nil then return v end
    -- Method 2: [] 1-based (Lua-Konvention, manche UE4SS Versionen)
    ok, v = pcall(function() return arr[idx0 + 1] end)
    if ok and v ~= nil then return v end
    -- Method 3: [] 0-based
    ok, v = pcall(function() return arr[idx0] end)
    if ok and v ~= nil then return v end
    -- Method 4: :GetObjectRef(idx) (für Struct-Arrays)
    ok, v = pcall(function() return arr:GetObjectRef(idx0) end)
    if ok and v ~= nil then return v end
    return nil
end

-- ForEach-Iteration für TArray (Alternative wenn Get/[] nicht funktioniert)
local function tarray_foreach(arr, fn)
    if arr == nil then return false end
    local ok = pcall(function()
        arr:ForEach(function(idx, elem)
            fn(idx, elem)
        end)
    end)
    return ok
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
    [5] = "Fish", [6] = "Berries", [7] = "Stone", [9] = "Mushrooms",
    [10] = "SmallGame",
}

-- EItemType enum (uint32): Fallback falls AResource.Type EItemType statt ENodeType ist
-- Werte aus EItemType.h (gezählt ab expliziten Werten)
local EITEM_INT_TO_NAME = {
    [14]  = "Iron",       -- IronOre
    [27]  = "Stone",      -- RoughStone
    [30]  = "Fish",       -- fish
    [36]  = "Deer",       -- deer_stag
    [145] = "Salt",       -- Salt
    [146] = "Clay",       -- Clay
    [171] = "Berries",    -- Berries
    [283] = "Stone",      -- DressedStone
    [330] = "SmallGame",  -- SmallGame
}

local function canonical_from_name(name)
    local s = safe_lower(tostring(name))
    -- try integer enum value first (ENodeType, then EItemType)
    local n = tonumber(s)
    if n ~= nil then
        if ENODE_INT_TO_NAME[n] then return ENODE_INT_TO_NAME[n] end
        if EITEM_INT_TO_NAME[n] then return EITEM_INT_TO_NAME[n] end
    end
    -- substring matching for FName / class name strings
    if s:find("stone", 1, true) then return "Stone" end
    if s:find("clay", 1, true) then return "Clay" end
    if s:find("salt", 1, true) then return "Salt" end
    if s:find("iron", 1, true) or s:find("ore", 1, true) then return "Iron" end
    if s:find("fish", 1, true) then return "Fish" end
    if s:find("berries", 1, true) or s:find("berry", 1, true) then return "Berries" end
    if s:find("deer", 1, true) or s:find("stag", 1, true) then return "Deer" end
    if s:find("smallgame", 1, true) or s:find("small_game", 1, true) then return "SmallGame" end
    if s:find("mushroom", 1, true) or s:find("pilz", 1, true) then return "Mushrooms" end
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
    -- AResource: resType (FName), Type (int32 ENodeType), amt, capacity
    local t = canonical_from_name(try_get(a, "resType"))
    if not t then
        -- fallback: Type property (ENodeType enum as int32)
        t = canonical_from_name(try_get(a, "Type"))
    end
    if not t then
        -- fallback: DisplayName
        t = canonical_from_name(try_get(a, "DisplayName"))
    end
    if not t then
        -- fallback: Classname
        local ok, cls = pcall(function() return safe_lower(a:GetClass():GetFullName()) end)
        if ok and cls then
            for k, _ in pairs(TARGETS) do
                if cls:find("resource_" .. safe_lower(k), 1, true) then
                    t = k
                    break
                end
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
    if not t then
        -- fallback: depositedGood.Type (EItemType int32)
        local good = try_get(a, "depositedGood")
        if good then
            t = canonical_from_name(try_get(good, "Type"))
        end
    end
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
-- Patch: Wildlife (ASMUnit mit Deer/Hare-Rolle)
-- Wildtiere sind KEINE AResource-Aktoren — jedes Tier ist ein ASMUnit.
-- Wir können Breeding beschleunigen (pregnancy) und tote Tiere zählen.
-- =========================
local function patch_wildlife_units(debugLeft)
    local units = FindAllOf("SMUnit")
    if not units then return 0, 0 end

    local wildCount = 0
    local patchedCount = 0

    for _, u in ipairs(units) do
        if u and u.IsValid and u:IsValid() and is_level_instance(u) then
            -- currentUnitRole ist EUnitRole (uint8)
            local role = try_get(u, "currentUnitRole")
            local roleNum = tonumber(tostring(role or ""))
            local canonical = roleNum and WILDLIFE_ROLES[roleNum]

            if not canonical then
                -- Fallback: assignedUnitRole
                role = try_get(u, "assignedUnitRole")
                roleNum = tonumber(tostring(role or ""))
                canonical = roleNum and WILDLIFE_ROLES[roleNum]
            end

            if canonical and TARGETS[canonical] then
                local isDead = try_get(u, "dead")
                if isDead ~= true then
                    wildCount = wildCount + 1

                    -- Breeding beschleunigen: pregnancy hochsetzen (näher am Spawn-Threshold)
                    local preg = to_num(try_get(u, "pregnancy"))
                    if preg ~= nil and preg >= 0 and preg < 0.9 then
                        if try_set(u, "pregnancy", 0.95) then
                            patchedCount = patchedCount + 1
                        end
                    end
                end

                if debugLeft.value > 0 and patchedCount > 0 then
                    debugLeft.value = debugLeft.value - 1
                    print(TAG .. "wildlife breeding boosted: " .. canonical
                        .. " | role=" .. tostring(roleNum))
                end
            end
        end
    end

    return patchedCount, wildCount
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

local function patch_settings_entry(entry, patched_count)
    if entry == nil then return patched_count end
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

            patched_count = patched_count + 1
        end
    end
    return patched_count
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

    -- Methode 1: Index-basierte Iteration (tarray_get probiert mehrere Zugriffsmethoden)
    for i0 = 0, len - 1 do
        local entry = tarray_get(data, i0)
        patched = patch_settings_entry(entry, patched)
    end

    -- Methode 2: ForEach als Fallback (für Struct-Arrays in neueren UE4SS Versionen)
    if patched == 0 then
        local forEachWorked = tarray_foreach(data, function(idx, elem)
            patched = patch_settings_entry(elem, patched)
        end)
        if forEachWorked and patched > 0 then
            print(TAG .. "ResourceSettings: ForEach-Methode hat funktioniert!")
        end
    end

    return patched > 0, ("patched entries=%d/%d"):format(patched, len)
end

-- =========================
-- Patch: Fruchtbarkeit auf Maximum (Getreide ohne Fertility-Requirement)
-- RTSMultiEngineCPP.fertilityGrid = TArray<FLinearColor>
-- Jede Zelle hat 4 Kanäle (RGBA) für die Getreide-Fruchtbarkeit.
-- Wir setzen alles auf 1.0 (Maximum) => Getreide wächst überall mit vollem Ertrag.
-- =========================
local function find_game_engine()
    local engine = nil
    local ok = pcall(function() engine = FindFirstOf("RTSMultiEngineCPP") end)
    if ok and engine and engine.IsValid and engine:IsValid() then return engine end
    return nil
end

local function patch_fertility_grid()
    local engine = find_game_engine()
    if not engine then return false, "RTSMultiEngineCPP not found" end

    -- Fertility-Grid muss aktiv sein
    try_set(engine, "enableFertilityGrid", true)

    local grid = try_get(engine, "fertilityGrid")
    if not grid then return false, "fertilityGrid not accessible" end

    local gridLen = tarray_num(grid)
    if not gridLen or gridLen <= 0 then
        return false, "fertilityGrid empty (len=" .. tostring(gridLen) .. ")"
    end

    local patched = 0
    local channels = {"R", "G", "B", "A"}

    -- Methode 1: Direkte Struct-Modifikation via GetObjectRef
    local method1Works = false
    local testCell = nil
    pcall(function() testCell = grid:GetObjectRef(0) end)
    if testCell then
        local testR = try_get(testCell, "R")
        if testR ~= nil then method1Works = true end
    end

    if method1Works then
        -- fertilityGrid: alle Zellen auf Maximum (1.0 pro Kanal)
        for i = 0, gridLen - 1 do
            local cell = nil
            pcall(function() cell = grid:GetObjectRef(i) end)
            if cell then
                local changed = false
                for _, ch in ipairs(channels) do
                    local cur = to_num(try_get(cell, ch))
                    if cur ~= nil and cur < 1.0 then
                        if try_set(cell, ch, 1.0) then changed = true end
                    end
                end
                if changed then patched = patched + 1 end
            end
        end

        -- fertilityGridLimits ebenfalls auf Maximum
        local limits = try_get(engine, "fertilityGridLimits")
        if limits then
            local limLen = tarray_num(limits) or 0
            for i = 0, limLen - 1 do
                local cell = nil
                pcall(function() cell = limits:GetObjectRef(i) end)
                if cell then
                    for _, ch in ipairs(channels) do
                        try_set(cell, ch, 1.0)
                    end
                end
            end
        end
    else
        -- Methode 2 (Fallback): changeFertilityCellUnclamped pro Zelle/CropType
        -- changeFertilityCellUnclamped(CellID, cropType, change) ist BlueprintCallable
        for i = 0, gridLen - 1 do
            for _, cropType in ipairs(GRAIN_CROP_TYPES) do
                local ok = pcall(function()
                    engine:changeFertilityCellUnclamped(i, cropType, 999.0)
                end)
                if ok then patched = patched + 1 end
            end
        end
    end

    -- Fertility-Overlay aktualisieren
    pcall(function() engine:redrawFertilityComplete() end)

    return patched > 0, ("method=%s | patched=%d/%d cells"):format(
        method1Works and "direct" or "changeFertility", patched, gridLen)
end

-- =========================
-- Diagnose: nicht erkannte Aktoren loggen (einmal pro Map)
-- =========================
local unmatchedLogged = false

local function log_unmatched_resource(a)
    if not CFG.DEBUG_UNMATCHED then return end
    local resType = tostring(try_get(a, "resType") or "nil")
    local typeInt = tostring(try_get(a, "Type") or "nil")
    local dispName = tostring(try_get(a, "DisplayName") or "nil")
    local cls = ""
    pcall(function() cls = tostring(a:GetClass():GetFullName()) end)
    print(TAG .. "UNMATCHED Resource | resType=" .. resType
        .. " | Type=" .. typeInt
        .. " | DisplayName=" .. dispName
        .. " | class=" .. cls)
end

local function log_unmatched_deposit(a)
    if not CFG.DEBUG_UNMATCHED then return end
    local depType = tostring(try_get(a, "depositType") or "nil")
    local limit = tostring(try_get(a, "Limit") or "nil")
    local rich = tostring(try_get(a, "bRichDeposit") or "nil")
    local cls = ""
    pcall(function() cls = tostring(a:GetClass():GetFullName()) end)
    print(TAG .. "UNMATCHED Deposit | depositType=" .. depType
        .. " | Limit=" .. limit
        .. " | bRichDeposit=" .. rich
        .. " | class=" .. cls)
end

-- =========================
-- Debug: vollständiger Scan aller Objekte (einmal pro Map)
-- =========================
local fullScanDone = false

local function debug_full_scan()
    if not CFG.DEBUG_FULL_SCAN then return end

    print(TAG .. "========== FULL SCAN START ==========")

    -- 1) AResource Aktoren
    print(TAG .. "--- AResource Aktoren ---")
    local resources = FindAllOf("Resource")
    if resources then
        local count = 0
        for _, a in ipairs(resources) do
            if a and a.IsValid and a:IsValid() and is_level_instance(a) then
                count = count + 1
                local resType   = tostring(try_get(a, "resType") or "?")
                local typeInt   = tostring(try_get(a, "Type") or "?")
                local dispName  = tostring(try_get(a, "DisplayName") or "?")
                local amt       = tostring(try_get(a, "amt") or "?")
                local capacity  = tostring(try_get(a, "capacity") or "?")
                local cls = "?"
                pcall(function() cls = tostring(a:GetClass():GetFName():ToString()) end)
                local matched = canonical_from_name(try_get(a, "resType"))
                    or canonical_from_name(try_get(a, "Type"))
                    or canonical_from_name(try_get(a, "DisplayName"))
                    or "NO_MATCH"
                print(TAG .. ("  [%d] class=%s | resType=%s | Type=%s | DisplayName=%s | amt=%s | capacity=%s | => %s")
                    :format(count, cls, resType, typeInt, dispName, amt, capacity, matched))
            end
        end
        print(TAG .. "  AResource total (level instances): " .. count)
    else
        print(TAG .. "  FindAllOf('Resource') returned nil")
    end

    -- 2) ADepositDecal Aktoren (mehrere Klassennamen probieren)
    print(TAG .. "--- ADepositDecal Aktoren ---")
    for _, depositClassName in ipairs({"DepositDecal", "BP_DepositDecal_C", "DepositDecalCPP"}) do
        local deposits = nil
        pcall(function() deposits = FindAllOf(depositClassName) end)
        if deposits then
            local count = 0
            for _, a in ipairs(deposits) do
                if a and a.IsValid and a:IsValid() and is_level_instance(a) then
                    count = count + 1
                    local depType = tostring(try_get(a, "depositType") or "?")
                    local limit   = tostring(try_get(a, "Limit") or "?")
                    local rich    = tostring(try_get(a, "bRichDeposit") or "?")
                    local cls = "?"
                    pcall(function() cls = tostring(a:GetClass():GetFName():ToString()) end)
                    local goodType = "?"
                    local good = try_get(a, "depositedGood")
                    if good then
                        goodType = tostring(try_get(good, "Type") or "?")
                    end
                    local matched = canonical_from_depositType(try_get(a, "depositType"))
                    if not matched and good then
                        matched = canonical_from_name(try_get(good, "Type"))
                    end
                    matched = matched or "NO_MATCH"
                    print(TAG .. ("  [%d] source=%s | class=%s | depositType=%s | goodType=%s | Limit=%s | bRichDeposit=%s | => %s")
                        :format(count, depositClassName, cls, depType, goodType, limit, rich, matched))
                end
            end
            print(TAG .. "  " .. depositClassName .. " total (level instances): " .. count)
        else
            print(TAG .. "  FindAllOf('" .. depositClassName .. "') returned nil")
        end
    end

    -- 3) ResourceNode Aktoren
    print(TAG .. "--- ResourceNode Aktoren ---")
    for _, className in ipairs({"ResourceNode", "BP_ResourceNode_C"}) do
        local nodes = FindAllOf(className)
        if nodes then
            local count = 0
            for _, n in ipairs(nodes) do
                if n and n.IsValid and n:IsValid() and is_level_instance(n) then
                    count = count + 1
                    local cls = "?"
                    pcall(function() cls = tostring(n:GetClass():GetFName():ToString()) end)
                    -- alle bekannten Type-Felder auslesen
                    local props = {}
                    for _, k in ipairs({"nodeType", "NodeType", "Type", "depositType", "DepositType",
                                        "bRichNode", "bRichDeposit", "bIsRich", "bRich", "bRichResource"}) do
                        local v = try_get(n, k)
                        if v ~= nil then
                            props[#props+1] = k .. "=" .. tostring(v)
                        end
                    end
                    local guessed = nil
                    for _, k in ipairs({"nodeType", "NodeType", "Type", "depositType", "DepositType"}) do
                        local v = try_get(n, k)
                        local c = canonical_from_name(v)
                        if c then guessed = c break end
                    end
                    print(TAG .. ("  [%d] source=%s | class=%s | %s | => %s")
                        :format(count, className, cls,
                            #props > 0 and table.concat(props, " | ") or "(keine Properties)",
                            guessed or "NO_MATCH"))
                end
            end
            print(TAG .. "  " .. className .. " total (level instances): " .. count)
        else
            print(TAG .. "  FindAllOf('" .. className .. "') returned nil")
        end
    end

    -- 4) Wildlife / SMUnit Aktoren
    print(TAG .. "--- SMUnit (Wildlife) Aktoren ---")
    local units = FindAllOf("SMUnit")
    if units then
        local wildCount = 0
        local totalUnits = 0
        local roleSummary = {}
        for _, u in ipairs(units) do
            if u and u.IsValid and u:IsValid() and is_level_instance(u) then
                totalUnits = totalUnits + 1
                local curRole = try_get(u, "currentUnitRole")
                local assignedRole = try_get(u, "assignedUnitRole")
                local curRoleNum = tonumber(tostring(curRole or ""))
                local assignedRoleNum = tonumber(tostring(assignedRole or ""))
                local canonical = (curRoleNum and WILDLIFE_ROLES[curRoleNum])
                    or (assignedRoleNum and WILDLIFE_ROLES[assignedRoleNum])
                if canonical then
                    wildCount = wildCount + 1
                    local isDead = try_get(u, "dead")
                    local preg = try_get(u, "pregnancy")
                    -- Zusammenfassung pro Typ
                    if not roleSummary[canonical] then
                        roleSummary[canonical] = { alive = 0, dead = 0 }
                    end
                    if isDead == true then
                        roleSummary[canonical].dead = roleSummary[canonical].dead + 1
                    else
                        roleSummary[canonical].alive = roleSummary[canonical].alive + 1
                    end
                    -- Erste paar pro Typ einzeln loggen
                    if (roleSummary[canonical].alive + roleSummary[canonical].dead) <= 5 then
                        print(TAG .. ("  wildlife: %s | curRole=%s | assignedRole=%s | dead=%s | pregnancy=%s")
                            :format(canonical, tostring(curRoleNum), tostring(assignedRoleNum),
                                tostring(isDead), tostring(preg)))
                    end
                end
            end
        end
        -- Zusammenfassung
        for name, s in pairs(roleSummary) do
            print(TAG .. ("  Wildlife-Zusammenfassung: %s => alive=%d, dead=%d"):format(name, s.alive, s.dead))
        end
        if wildCount == 0 then
            -- Alle unique Rollen sammeln und die ersten 10 Units loggen
            print(TAG .. "  KEINE Wildlife erkannt (erwarte Deer=8, Hare=20)! Erste 10 SMUnit-Rollen:")
            local shown = 0
            local allRoles = {}
            for _, u in ipairs(units) do
                if u and u.IsValid and u:IsValid() and is_level_instance(u) then
                    local curRole = tonumber(tostring(try_get(u, "currentUnitRole") or ""))
                    if curRole then allRoles[curRole] = (allRoles[curRole] or 0) + 1 end
                    if shown < 10 then
                        shown = shown + 1
                        local cls = "?"
                        pcall(function() cls = tostring(u:GetClass():GetFName():ToString()) end)
                        print(TAG .. ("  [%d] class=%s | currentUnitRole=%s | assignedUnitRole=%s")
                            :format(shown, cls, tostring(curRole or "?"),
                                tostring(try_get(u, "assignedUnitRole") or "?")))
                    end
                end
            end
            -- Rollen-Zusammenfassung
            local roleSumParts = {}
            for r, c in pairs(allRoles) do
                roleSumParts[#roleSumParts+1] = ("role%d=%d"):format(r, c)
            end
            print(TAG .. "  Alle Rollen: " .. table.concat(roleSumParts, ", "))
        end
        print(TAG .. "  SMUnit total=" .. totalUnits .. " | wildlife erkannt=" .. wildCount)
    else
        print(TAG .. "  FindAllOf('SMUnit') returned nil")
    end

    -- 5) ResourceSettings dump (mit TArray-Zugriffsdiagnose)
    print(TAG .. "--- ResourceSettings ---")
    local settings = find_resource_settings()
    if settings then
        local data = try_get(settings, "ResourceNodeData")
        local len = data and tarray_num(data) or 0
        print(TAG .. "  ResourceNodeData entries: " .. tostring(len))
        print(TAG .. "  ResourceNodeData type: " .. type(data) .. " | tostring: " .. tostring(data))

        -- Diagnose: welche TArray-Zugriffsmethoden funktionieren?
        if data and len and len > 0 then
            local method1 = pcall(function() return data:Get(0) end) and "ja" or "nein"
            local method2 = pcall(function() return data[1] end) and "ja" or "nein"
            local method3 = pcall(function() return data[0] end) and "ja" or "nein"
            local method4 = pcall(function() return data:GetObjectRef(0) end) and "ja" or "nein"
            local method5 = "nein"
            pcall(function()
                data:ForEach(function(idx, elem) method5 = "ja" end)
            end)
            print(TAG .. "  TArray-Zugriff: Get=" .. method1
                .. " | [1]=" .. method2
                .. " | [0]=" .. method3
                .. " | GetObjectRef=" .. method4
                .. " | ForEach=" .. method5)

            -- Index-basierter Zugriff
            local foundEntries = false
            for i0 = 0, len - 1 do
                local entry = tarray_get(data, i0)
                if entry then
                    foundEntries = true
                    local entryType = tostring(try_get(entry, "Type") or "?")
                    local canonical = canonical_from_name(try_get(entry, "Type")) or "NO_MATCH"
                    local props = try_get(entry, "Properties")
                    local minAmt = props and tostring(try_get(props, "MinResourceAmount") or "?") or "?"
                    local maxAmt = props and tostring(try_get(props, "MaxResourceAmount") or "?") or "?"
                    print(TAG .. ("  [%d] Type=%s | => %s | MinAmt=%s | MaxAmt=%s | props=%s")
                        :format(i0, entryType, canonical, minAmt, maxAmt, tostring(props)))
                end
            end

            -- ForEach als Fallback
            if not foundEntries then
                print(TAG .. "  Index-Zugriff fehlgeschlagen, versuche ForEach...")
                tarray_foreach(data, function(idx, elem)
                    if elem then
                        local entryType = tostring(try_get(elem, "Type") or "?")
                        local canonical = canonical_from_name(try_get(elem, "Type")) or "NO_MATCH"
                        local props = try_get(elem, "Properties")
                        print(TAG .. ("  [ForEach %d] Type=%s | => %s | props=%s | elemType=%s")
                            :format(idx, entryType, canonical, tostring(props), type(elem)))
                    end
                end)
            end
        end
    else
        print(TAG .. "  ResourceSettings NICHT gefunden")
    end

    -- 6) Fertility Grid Diagnose
    print(TAG .. "--- Fertility Grid ---")
    local engine = find_game_engine()
    if engine then
        local fertEnabled = try_get(engine, "enableFertilityGrid")
        print(TAG .. "  enableFertilityGrid: " .. tostring(fertEnabled))

        local grid = try_get(engine, "fertilityGrid")
        local limits = try_get(engine, "fertilityGridLimits")
        local gridLen = grid and tarray_num(grid) or 0
        local limitsLen = limits and tarray_num(limits) or 0
        print(TAG .. "  fertilityGrid entries: " .. tostring(gridLen))
        print(TAG .. "  fertilityGridLimits entries: " .. tostring(limitsLen))

        -- Erste 5 Zellen als Beispiel anzeigen
        if grid and gridLen and gridLen > 0 then
            local sampleCount = math.min(5, gridLen)
            for i = 0, sampleCount - 1 do
                local cell = nil
                pcall(function() cell = grid:GetObjectRef(i) end)
                if cell then
                    local r = tostring(try_get(cell, "R") or "?")
                    local g = tostring(try_get(cell, "G") or "?")
                    local b = tostring(try_get(cell, "B") or "?")
                    local a = tostring(try_get(cell, "A") or "?")
                    print(TAG .. ("  grid[%d] R=%s G=%s B=%s A=%s"):format(i, r, g, b, a))
                else
                    -- Fallback: direkte Indizierung
                    local ok, v = pcall(function() return grid[i] end)
                    print(TAG .. ("  grid[%d] GetObjectRef=nil | direct=%s"):format(i, tostring(v)))
                end
            end

            -- Zugriffsmethoden testen
            local m1 = pcall(function() return grid:GetObjectRef(0) end) and "ja" or "nein"
            local m2 = pcall(function() return grid:Get(0) end) and "ja" or "nein"
            local m3 = pcall(function() return grid[0] end) and "ja" or "nein"
            print(TAG .. "  Zugriff: GetObjectRef=" .. m1 .. " | Get=" .. m2 .. " | [0]=" .. m3)
        end
    else
        print(TAG .. "  RTSMultiEngineCPP NICHT gefunden")
    end

    print(TAG .. "========== FULL SCAN END ==========")
end

-- =========================
-- Main pass
-- =========================
local function patch_pass(debugLeft)
    local total = 0
    local patched = 0
    local unmatchedRes = 0
    local unmatchedDep = 0

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
                    elseif not unmatchedLogged then
                        unmatchedRes = unmatchedRes + 1
                        if unmatchedRes <= 5 then
                            log_unmatched_resource(a)
                        end
                    end
                end
            end
        end
    end

    if CFG.PATCH_RUNTIME_DEPOSITS then
        -- Mehrere Klassennamen probieren (Basis + BP-Subklassen)
        for _, depositClass in ipairs({"DepositDecal", "BP_DepositDecal_C", "DepositDecalCPP"}) do
            local deposits = nil
            pcall(function() deposits = FindAllOf(depositClass) end)
            if deposits then
                for _, a in ipairs(deposits) do
                    if a and a.IsValid and a:IsValid() and is_level_instance(a) then
                        total = total + 1
                        if patch_deposit_decal(a) then
                            patched = patched + 1
                            if debugLeft.value > 0 then
                                debugLeft.value = debugLeft.value - 1
                                print(TAG .. "patched " .. depositClass .. ": " .. tostring(a:GetFullName()))
                            end
                        elseif not unmatchedLogged then
                            unmatchedDep = unmatchedDep + 1
                            if unmatchedDep <= 5 then
                                log_unmatched_deposit(a)
                            end
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

    -- Wildlife: ASMUnit-Tiere (Deer, Hare/SmallGame)
    local wildPatched = 0
    local wildAlive = 0
    if CFG.PATCH_RUNTIME_WILDLIFE then
        wildPatched, wildAlive = patch_wildlife_units(debugLeft)
        patched = patched + wildPatched
    end

    -- Diagnose nur im ersten Pass loggen
    if not unmatchedLogged then
        if unmatchedRes > 0 or unmatchedDep > 0 then
            print(TAG .. "DIAGNOSE: " .. unmatchedRes .. " unerkannte Resources, " .. unmatchedDep .. " unerkannte Deposits")
        end
        if wildAlive > 0 then
            print(TAG .. "Wildlife: " .. wildAlive .. " lebende Tiere gefunden, " .. wildPatched .. " breeding boosted")
        end
        unmatchedLogged = true
    end

    return patched, total
end

-- =========================
-- Loop: pro Map ein paar Pässe
-- =========================
local tries = 0
local lastMap = ""
local didSettings = false
local didFertility = false

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
        didFertility = false
        unmatchedLogged = false
        fullScanDone = false
        print(TAG .. "map: " .. mapname)
    end

    if not is_gameplay_map(mapname) then
        return false
    end

    tries = tries + 1

    if tries < CFG.START_DELAY_PASSES then
        return false
    end

    -- Debug: vollständiger Scan (einmal pro Map, im ersten Pass)
    if not fullScanDone then
        debug_full_scan()
        fullScanDone = true
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

    -- Fruchtbarkeit einmal pro Map auf Maximum setzen
    if CFG.PATCH_FERTILITY and not didFertility then
        local ok, msg = patch_fertility_grid()
        if ok then
            print(TAG .. "Fertility grid patched: " .. msg)
        else
            print(TAG .. "Fertility patch skipped: " .. tostring(msg))
        end
        didFertility = true
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

-- =========================
-- Periodischer Fertility-Refresh
-- Das Spiel verbraucht Fruchtbarkeit beim Anbau.
-- Dieser Loop setzt sie regelmäßig wieder auf Maximum.
-- =========================
if CFG.PATCH_FERTILITY and CFG.FERTILITY_REFRESH_SEC > 0 then
    local fertRefreshMap = ""
    LoopAsync(CFG.FERTILITY_REFRESH_SEC * 1000, function()
        local world = UEHelpers.GetWorld()
        if not world or not world.IsValid or not world:IsValid() then
            return false
        end

        local mapname = get_map_name(world)
        if not is_gameplay_map(mapname) then
            return false
        end

        -- Map-Wechsel tracken (nur loggen)
        if mapname ~= fertRefreshMap then
            fertRefreshMap = mapname
            print(TAG .. "Fertility refresh active for map: " .. mapname)
        end

        local ok, msg = patch_fertility_grid()
        if ok then
            print(TAG .. "Fertility refresh: " .. msg)
        end

        return false  -- läuft endlos weiter
    end)
    print(TAG .. "Fertility refresh timer started (every " .. CFG.FERTILITY_REFRESH_SEC .. "s)")
end