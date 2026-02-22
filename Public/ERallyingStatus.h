#pragma once
#include "CoreMinimal.h"
#include "ERallyingStatus.generated.h"

UENUM(BlueprintType)
enum class ERallyingStatus : uint8 {
    Disbanded,
    Rallying,
    Rallied,
};

