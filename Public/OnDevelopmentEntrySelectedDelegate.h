#pragma once
#include "CoreMinimal.h"
#include "OnDevelopmentEntrySelectedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDevelopmentEntrySelected, int32, SelectedLevel);

