#pragma once
#include "CoreMinimal.h"
#include "OnProficiencyChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnProficiencyChanged, float, OldProficiency, float, NewProficiency);

