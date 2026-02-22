#pragma once
#include "CoreMinimal.h"
#include "EControlInputMode.h"
#include "OnControlHookInputModeChangeDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnControlHookInputModeChange, EControlInputMode, nextInputMode, EControlInputMode, lastInputMode);

