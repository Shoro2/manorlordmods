#pragma once
#include "CoreMinimal.h"
#include "OnControlHookUiHasPriorityDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnControlHookUiHasPriority, bool, hasPriority);

