#pragma once
#include "CoreMinimal.h"
#include "LivingSpaceData.generated.h"

USTRUCT(BlueprintType)
struct FLivingSpaceData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 constructed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 unconstructed;
    
    MANORLORDS_API FLivingSpaceData();
};

