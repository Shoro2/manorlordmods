#pragma once
#include "CoreMinimal.h"
#include "ResourceSoundData.generated.h"

class USoundBase;

USTRUCT(BlueprintType)
struct FResourceSoundData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* pickup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* putdown;
    
    MANORLORDS_API FResourceSoundData();
};

