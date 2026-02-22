#pragma once
#include "CoreMinimal.h"
#include "EAttackMethod.generated.h"

UENUM(BlueprintType)
enum class EAttackMethod : uint8 {
    Mixed,
    Slash,
    Stab,
};

