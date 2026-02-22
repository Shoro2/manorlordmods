#pragma once
#include "CoreMinimal.h"
#include "EPeriodType.generated.h"

UENUM(BlueprintType)
enum class EPeriodType : uint8 {
    None,
    Monthly,
    Yearly,
    EveryOtherMonth,
    Once,
    TwiceAYear,
};

