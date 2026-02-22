#pragma once
#include "CoreMinimal.h"
#include "EPushStance.generated.h"

UENUM(BlueprintType)
enum class EPushStance : uint8 {
    GiveGround,
    StandGround,
    Push,
    MissileAlert,
    Balanced,
};

