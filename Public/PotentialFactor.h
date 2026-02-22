#pragma once
#include "CoreMinimal.h"
#include "PotentialFactor.generated.h"

USTRUCT(BlueprintType)
struct FPotentialFactor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName factorName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Effect;
    
    MANORLORDS_API FPotentialFactor();
};

