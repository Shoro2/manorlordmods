#pragma once
#include "CoreMinimal.h"
#include "ControlHookFlow.generated.h"

USTRUCT(BlueprintType)
struct MANORLORDS_API FControlHookFlow {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool inFullscreenUi;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool inTutorial;
    
    FControlHookFlow();
};

