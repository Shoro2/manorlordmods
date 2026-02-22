#pragma once
#include "CoreMinimal.h"
#include "OnPaperMapViewChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPaperMapViewChanged, bool, bIsPaperMapView);

