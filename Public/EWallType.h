#pragma once
#include "CoreMinimal.h"
#include "EWallType.generated.h"

UENUM(BlueprintType)
enum class EWallType : uint8 {
    None,
    Fence,
    Wooden,
    StoneLow,
    StoneHigh,
};

