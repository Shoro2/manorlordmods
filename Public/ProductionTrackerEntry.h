#pragma once
#include "CoreMinimal.h"
#include "ProductionTrackerEntry.generated.h"

USTRUCT(BlueprintType)
struct FProductionTrackerEntry {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int64 DayProduced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 QuantityProduced;
    
    MANORLORDS_API FProductionTrackerEntry();
};

