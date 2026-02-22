#pragma once
#include "CoreMinimal.h"
#include "EGrowthModifier.generated.h"

UENUM(BlueprintType)
enum class EGrowthModifier : uint8 {
    None,
    Base,
    NoBurgagePlotAvailability,
    Approval,
};

