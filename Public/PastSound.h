#pragma once
#include "CoreMinimal.h"
#include "PastSound.generated.h"

class USoundBase;

USTRUCT(BlueprintType)
struct FPastSound {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Time;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* Sound;
    
    MANORLORDS_API FPastSound();
};

