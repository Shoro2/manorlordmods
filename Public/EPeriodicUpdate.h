#pragma once
#include "CoreMinimal.h"
#include "EPeriodicUpdate.generated.h"

UENUM(BlueprintType)
enum class EPeriodicUpdate : uint8 {
    None,
    SeasonalResourceGrowth,
    SheepElevationDeath,
};

