#pragma once
#include "CoreMinimal.h"
#include "EGameGoals.generated.h"

UENUM(BlueprintType)
enum class EGameGoals : uint8 {
    Endless,
    Conquest,
    Growth,
    Dominance,
};

