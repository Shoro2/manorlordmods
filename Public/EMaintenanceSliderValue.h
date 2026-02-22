#pragma once
#include "CoreMinimal.h"
#include "EMaintenanceSliderValue.generated.h"

UENUM(BlueprintType)
enum class EMaintenanceSliderValue : uint8 {
    Half,
    Normal,
    Double,
    Invalid,
};

