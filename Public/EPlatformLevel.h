#pragma once
#include "CoreMinimal.h"
#include "EPlatformLevel.generated.h"

UENUM(BlueprintType)
enum class EPlatformLevel : uint8 {
    None,
    Open,
    Hoarding,
    Closed,
};

