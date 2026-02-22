#pragma once
#include "CoreMinimal.h"
#include "ECursorMode.generated.h"

UENUM(BlueprintType)
enum class ECursorMode : uint8 {
    Default,
    Attack,
    Spyglass,
    Grab,
    Missile,
    MixedAttack,
    Torch,
    Build,
};

