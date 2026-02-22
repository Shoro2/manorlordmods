#pragma once
#include "CoreMinimal.h"
#include "ESettlementType.generated.h"

UENUM(BlueprintType)
enum class ESettlementType : uint8 {
    None,
    Town,
    FarmingVillage,
    ForestVillage,
    MiningOutpost,
    Outpost,
};

