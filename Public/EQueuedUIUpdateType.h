#pragma once
#include "CoreMinimal.h"
#include "EQueuedUIUpdateType.generated.h"

UENUM(BlueprintType)
enum class EQueuedUIUpdateType : uint8 {
    RegionalStock,
    RegionalSurplus,
};

