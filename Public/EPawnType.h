#pragma once
#include "CoreMinimal.h"
#include "EPawnType.generated.h"

UENUM(BlueprintType)
enum class EPawnType : uint8 {
    HumanPlayer,
    Adversary,
    AIControlled,
};

