#pragma once
#include "CoreMinimal.h"
#include "EChallengeStatus.generated.h"

UENUM(BlueprintType)
enum class EChallengeStatus : uint8 {
    Winning,
    Losing,
    Combat,
    Paused,
};

