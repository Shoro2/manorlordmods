#pragma once
#include "CoreMinimal.h"
#include "ECameraDistance.generated.h"

UENUM(BlueprintType)
enum class ECameraDistance : uint8 {
    Invalid,
    SuperClose,
    Close,
    Mid,
    Far,
};

