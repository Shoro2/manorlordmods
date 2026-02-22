#pragma once
#include "CoreMinimal.h"
#include "MaintenanceTrackerData.generated.h"

USTRUCT(BlueprintType)
struct FMaintenanceTrackerData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DurabilityLeft;
    
    MANORLORDS_API FMaintenanceTrackerData();
};

