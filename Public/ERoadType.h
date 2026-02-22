#pragma once
#include "CoreMinimal.h"
#include "ERoadType.generated.h"

UENUM(BlueprintType)
enum class ERoadType : uint8 {
    Regular,
    Dummy,
    Border,
    Wall,
    Stream,
};

