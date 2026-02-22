#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "HeightmapGen.generated.h"

class UTextureRenderTarget2D;

UCLASS(Blueprintable)
class MANORLORDS_API AHeightmapGen : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* RT_heightmap;
    
    AHeightmapGen(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void refreshHeightmap();
    
};

