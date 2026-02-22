#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "SnapDebris.generated.h"

class AActor;
class ASnapDebrisActor;
class UDataTable;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MANORLORDS_API USnapDebris : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<ASnapDebrisActor*> activeDebris;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* debrisTable;
    
public:
    USnapDebris(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool ReplaceActor(FName debrisName, AActor* actorToReplace, bool destroyReplacedActor);
    
    UFUNCTION(BlueprintCallable)
    int32 CleanupDebris(FVector Location, float MaxRange, FName FilterName);
    
    UFUNCTION(BlueprintCallable)
    bool AtTransform(FName debrisName, FTransform tr);
    
    UFUNCTION(BlueprintCallable)
    bool AtLocationRotation(FName debrisName, FVector Location, FRotator Rotation);
    
};

