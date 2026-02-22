#pragma once
#include "CoreMinimal.h"
#include "EVictoryStatus.generated.h"

UENUM(BlueprintType)
enum class EVictoryStatus : uint8 {
    Ongoing,
    Lost,
    Victorious,
};

