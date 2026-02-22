#pragma once
#include "CoreMinimal.h"
#include "ConsumptionLimit.generated.h"

USTRUCT(BlueprintType)
struct FConsumptionLimit {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, int32> limitPerGoodType;
    
    MANORLORDS_API FConsumptionLimit();
};

