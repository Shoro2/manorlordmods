#pragma once
#include "CoreMinimal.h"
#include "ApprovalEffect.generated.h"

USTRUCT(BlueprintType)
struct FApprovalEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    MANORLORDS_API FApprovalEffect();
};

