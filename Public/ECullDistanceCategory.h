#pragma once
#include "CoreMinimal.h"
#include "ECullDistanceCategory.generated.h"

UENUM(BlueprintType)
enum class ECullDistanceCategory : uint8 {
    Building,
    Far,
    Mid,
    Close,
};

