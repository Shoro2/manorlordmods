#pragma once
#include "CoreMinimal.h"
#include "ECollapseModifier.generated.h"

UENUM(BlueprintType)
enum class ECollapseModifier : uint8 {
    None,
    Proximity,
    Maintenance,
    MAX,
};

