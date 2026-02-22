#pragma once
#include "CoreMinimal.h"
#include "OnPerkEntryClickedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPerkEntryClicked, const FName, InPerkType);

