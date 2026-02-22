#pragma once
#include "CoreMinimal.h"
#include "MaintenanceSupply.generated.h"

USTRUCT(BlueprintType)
struct FMaintenanceSupply {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> Types;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Frequency;
    
    MANORLORDS_API FMaintenanceSupply();
};

