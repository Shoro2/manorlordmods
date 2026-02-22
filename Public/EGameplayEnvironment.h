#pragma once
#include "CoreMinimal.h"
#include "EGameplayEnvironment.generated.h"

UENUM(BlueprintType)
enum class EGameplayEnvironment : uint8 {
    None,
    Meadow,
    Woodland,
    Farmland,
    Rural,
    Urban,
};

