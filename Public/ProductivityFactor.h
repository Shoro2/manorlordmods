#pragma once
#include "CoreMinimal.h"
#include "ProductivityFactor.generated.h"

USTRUCT(BlueprintType)
struct FProductivityFactor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName factorName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Strength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsPerk;
    
    MANORLORDS_API FProductivityFactor();
};

