#pragma once
#include "CoreMinimal.h"
#include "EBuildingFunction.generated.h"

UENUM(BlueprintType)
enum class EBuildingFunction : uint8 {
    Default,
    Residential,
    Manor,
    Stall,
    Church,
    Granary,
    Warehouse,
    Temporary,
    WaterSource,
    Tradepoint,
    Pasture,
    Stable,
    Field,
    Landscape,
    Trader,
    Market,
    Tavern,
    Siege,
    Mine,
    Cosmetic,
    Scenario,
    Rubble,
};

