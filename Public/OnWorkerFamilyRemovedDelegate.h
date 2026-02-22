#pragma once
#include "CoreMinimal.h"
#include "OnWorkerFamilyRemovedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWorkerFamilyRemoved, const int32, RemovedFamilyID);

