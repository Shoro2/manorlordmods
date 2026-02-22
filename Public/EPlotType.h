#pragma once
#include "CoreMinimal.h"
#include "EPlotType.generated.h"

UENUM(BlueprintType)
enum class EPlotType : uint8 {
    None,
    Field,
    Pasture,
    Residential,
    Market,
    Bailey,
};

