#pragma once
#include "CoreMinimal.h"
#include "CostArray.generated.h"

USTRUCT(BlueprintType)
struct FCostArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> Costs;
    
    MANORLORDS_API FCostArray();
};

