#pragma once
#include "CoreMinimal.h"
#include "ETradePartnerLimit.generated.h"

UENUM(BlueprintType)
enum class ETradePartnerLimit : uint8 {
    None,
    FreeMerchants,
    Local,
    Owned,
};

