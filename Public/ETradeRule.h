#pragma once
#include "CoreMinimal.h"
#include "ETradeRule.generated.h"

UENUM(BlueprintType)
enum class ETradeRule : uint8 {
    NoTrade,
    Import,
    Export,
    Full,
};

