#pragma once
#include "CoreMinimal.h"
#include "EPixelFedBackendId.h"
#include "PixelFedBackendChoices.h"
#include "PixelFedFullChoiceState.generated.h"

USTRUCT(BlueprintType)
struct MANORLORDS_API FPixelFedFullChoiceState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPixelFedBackendId activeBackendId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPixelFedBackendChoices> backendChoices;
    
    FPixelFedFullChoiceState();
};

