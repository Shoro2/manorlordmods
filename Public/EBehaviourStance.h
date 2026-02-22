#pragma once
#include "CoreMinimal.h"
#include "EBehaviourStance.generated.h"

UENUM(BlueprintType)
enum class EBehaviourStance : uint8 {
    Neutral,
    Aggressive,
    Defensive,
};

