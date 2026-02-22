#pragma once
#include "CoreMinimal.h"
#include "ExpertiseData.generated.h"

USTRUCT(BlueprintType)
struct FExpertiseData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Expertise;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpertiseThisMonth;
    
    MANORLORDS_API FExpertiseData();
};

