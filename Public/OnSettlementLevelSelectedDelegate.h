#pragma once
#include "CoreMinimal.h"
#include "OnSettlementLevelSelectedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSettlementLevelSelected, const int32, SettlementLevel);

