#pragma once
#include "CoreMinimal.h"
#include "EConstructionStage.generated.h"

UENUM(BlueprintType)
enum class EConstructionStage : uint8 {
    Constructed,
    Upgrading,
    Unconstructed,
    ConstructedOrBeingUpgraded,
    AnyStage,
    MAX,
};

