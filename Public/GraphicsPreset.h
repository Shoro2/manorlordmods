#pragma once
#include "CoreMinimal.h"
#include "GraphicsPreset.generated.h"

USTRUCT(BlueprintType)
struct FGraphicsPreset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> Setting;
    
    MANORLORDS_API FGraphicsPreset();
};

