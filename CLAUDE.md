# CLAUDE.md

## Project Overview

This repository contains **modding resources for Manor Lords**, a medieval city-builder/strategy game built on Unreal Engine. It includes:

1. **C++ header stubs** (`Public/`) — reverse-engineered UE4/UE5 header declarations exposing Manor Lords' internal classes, structs, and enums for mod development.
2. **C++ implementation stubs** (`Private/`) — corresponding default constructor implementations with initial property values.
3. **ML_ResourcePatcher** — a UE4SS Lua mod that patches in-game resource amounts and deposit richness at runtime.

## Repository Structure

```
/
├── Public/                    # 445 header files (.h) — public API surface
│   ├── E*.h                   # 97 UENUM enum definitions (ENodeType, EBuildingType, etc.)
│   ├── *Settings.h            # UDeveloperSettings subclasses (config/balance data)
│   ├── Saved*.h               # Serialization structs for save games
│   └── *.h                    # USTRUCT and UCLASS declarations
├── Private/                   # 331 source files (.cpp) — constructor implementations
├── ML_ResourcePatcher/        # UE4SS Lua mod
│   ├── enabled.txt            # empty = mod enabled
│   └── scripts/
│       └── main.lua           # Resource patching script
└── .gitattributes
```

## Languages & Technologies

- **C++ (Unreal Engine)** — Headers use UE reflection macros (`UCLASS`, `USTRUCT`, `UENUM`, `UPROPERTY`, `UFUNCTION`, `GENERATED_BODY`)
- **Lua** — UE4SS scripting for runtime mod (ML_ResourcePatcher)
- **Module name**: `MANORLORDS_API` (used in `_API` export macros)

## Key Conventions

### C++ Headers (Public/)

- Every header uses `#pragma once` and includes `CoreMinimal.h`
- Auto-generated reflection headers follow pattern: `#include "<ClassName>.generated.h"`
- Cross-module dependencies noted via comments: `//CROSS-MODULE INCLUDE V2: -ModuleName=...`
- All `UPROPERTY` fields typically use `BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true)`
- Config/settings classes derive from `UDeveloperSettings` and add `Config=Game`
- Structs are prefixed with `F` (e.g., `FArmy`, `FBattle`), classes with `A` (actors) or `U` (objects)
- Enums are prefixed with `E` and live in separate `E*.h` files

### C++ Implementations (Private/)

- Each `.cpp` includes only its corresponding header
- Constructors initialize all properties to default values (zero, false, nullptr, etc.)
- No business logic — these are stubs for linking against the game module

### Lua Mod (ML_ResourcePatcher)

- Uses **UE4SS** Lua API (`FindAllOf`, `FindFirstOf`, `StaticFindObject`, `LoopAsync`, `UEHelpers`)
- Comments and config labels are in German
- Defensive programming throughout: `pcall` wrappers, nil checks, validity checks
- Config block (`CFG`) at top controls behavior via kill-switches
- Target values block (`TARGETS`) defines resource amounts and rich-deposit flags
- Runs as async loop (`LoopAsync`) with multiple passes after map load

## Game Domain Context

Manor Lords is a medieval city-builder. Key domain concepts in the codebase:

- **Resources**: Stone, Clay, Salt, Iron, Fish, Berries, Deer, SmallGame — managed via `AResource`, `AResourceNode`, `ADepositDecal`
- **Buildings**: Templates, construction stages, extensions, maintenance systems
- **Units/Squads**: Military squads with equipment, formations, roles, morale
- **Regions**: Territory claiming, development, production tracking
- **Economy**: Trade, production chains, item management, artisan data
- **Approval**: Citizen satisfaction system with multiple weighted factors
- **AI**: Region-based AI with building requests, commands, diplomacy

## Working with This Codebase

### Adding New Header Stubs

1. Create `Public/<ClassName>.h` with `#pragma once`, `CoreMinimal.h`, and `.generated.h` include
2. Use appropriate UE macro (`UCLASS`, `USTRUCT`, or `UENUM`)
3. Add `MANORLORDS_API` export macro for classes/structs with exported constructors
4. Create matching `Private/<ClassName>.cpp` with default constructor

### Modifying the Lua Mod

- Edit `ML_ResourcePatcher/scripts/main.lua`
- Add new resource types to the `TARGETS` table
- Adjust `CFG` values for timing and debug behavior
- Always wrap UE object access in `pcall` / validity checks to prevent crashes
- The mod is enabled when `ML_ResourcePatcher/enabled.txt` exists (content irrelevant)

## No Build System

This repository has no build system, Makefile, or package manager. The C++ headers are reference stubs meant to be consumed by an Unreal Engine project or modding toolchain externally. The Lua mod is loaded directly by the UE4SS framework at runtime.

## No Tests

There is no test suite in this repository. The Lua mod can be tested by loading it in-game via UE4SS.
