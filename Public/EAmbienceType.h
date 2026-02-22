#pragma once
#include "CoreMinimal.h"
#include "EAmbienceType.generated.h"

UENUM(BlueprintType)
enum class EAmbienceType : uint8 {
    None,
    ForestBirds,
    FieldBirds,
    ForestWinter,
    FieldWinter,
    VillageSpring,
    VillageWinter,
    TownSpring,
    TownWinter,
    CombatLarge,
    CombatSmall,
    Unrest,
    Plague,
    RiverSpring,
    RiverWinter,
    Sea,
    Drought,
    Night,
};

