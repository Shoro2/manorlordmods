#pragma once
#include "CoreMinimal.h"
#include "LoyaltyFactor.generated.h"

USTRUCT(BlueprintType)
struct FLoyaltyFactor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    MANORLORDS_API FLoyaltyFactor();
};

