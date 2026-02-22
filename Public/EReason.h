#pragma once
#include "CoreMinimal.h"
#include "EReason.generated.h"

UENUM(BlueprintType)
enum class EReason : uint8 {
    None,
    Colliding,
    MissingResources,
    NoOwnership,
    MissingUpgrade,
    MissingTradition,
    WrongRegion,
};

