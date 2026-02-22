#pragma once
#include "CoreMinimal.h"
#include "EMaintenanceCombo.generated.h"

UENUM(BlueprintType)
enum class EMaintenanceCombo : uint8 {
    Unmaintained,
    MaintainedHalf,
    MaintainedDouble,
    MAX,
};

