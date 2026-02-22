#pragma once
#include "CoreMinimal.h"
#include "EPixelFedBackendId.h"
#include "PixelFedBackend.h"
#include "PixelFedState.generated.h"

USTRUCT(BlueprintType)
struct MANORLORDS_API FPixelFedState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EPixelFedBackendId, FPixelFedBackend> backends;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 frameGenMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool showFps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float lastFrameFps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPixelFedBackendId platformPreferedBackendId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPixelFedBackendId activeBackendId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPixelFedBackendId playerPreferedBackendId;
    
    FPixelFedState();
};

