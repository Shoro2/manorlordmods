#pragma once
#include "CoreMinimal.h"
#include "EMaintenanceStatus.generated.h"

UENUM(BlueprintType)
enum class EMaintenanceStatus : uint8 {
    NoMaintenanceNeeded,
    Maintained,
    Pending,
    Unmaintained,
};

