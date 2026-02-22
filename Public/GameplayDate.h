#pragma once
#include "CoreMinimal.h"
#include "GameplayDate.generated.h"

USTRUCT(BlueprintType)
struct FGameplayDate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 dayOfTheMonth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 monthOfTheYear;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 yearsSurvivedTotal;
    
    MANORLORDS_API FGameplayDate();
};

