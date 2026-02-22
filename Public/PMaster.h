#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
#include "Proj.h"
#include "PMaster.generated.h"

class ARTSMultiEngineCPP;
class ASMUnit;
class UInstancedStaticMeshComponent;

UCLASS(Blueprintable)
class MANORLORDS_API APMaster : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARTSMultiEngineCPP* masterPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle projUpdateHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FProj> projArr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* InstanceArrow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* InstanceTorch;
    
    APMaster(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void updateProj();
    
    UFUNCTION(BlueprintCallable)
    void shootProjectile(int32 Type, FVector Start, FVector End, float Height, ASMUnit* shooter);
    
};

