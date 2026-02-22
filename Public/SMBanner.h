#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshActor -FallbackName=SkeletalMeshActor
#include "SMBanner.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class MANORLORDS_API ASMBanner : public ASkeletalMeshActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FrameData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* MI_bannerMaterial;
    
    ASMBanner(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void setFrames(FVector newFrameData);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getFrames();
    
    UFUNCTION(BlueprintCallable)
    void createDynamicMaterial(const float& colorA, const float& colorB, const float& heraldry);
    
};

