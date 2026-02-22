#pragma once
#include "CoreMinimal.h"
#include "LordSetupData.generated.h"

class UTextureRenderTarget2D;

USTRUCT(BlueprintType)
struct FLordSetupData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* coatOfArms;
    
    MANORLORDS_API FLordSetupData();
};

