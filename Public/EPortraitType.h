#pragma once
#include "CoreMinimal.h"
#include "EPortraitType.generated.h"

UENUM(BlueprintType)
enum class EPortraitType : uint8 {
    Lord,
    Lady,
    Bandit,
    Priest,
};

