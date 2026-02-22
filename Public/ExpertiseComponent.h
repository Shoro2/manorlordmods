#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "ArtisanData.h"
#include "ExpertiseComponent.generated.h"

class UProficiencySettings;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UExpertiseComponent : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UProficiencySettings* ProficiencySettings;
    
public:
    UExpertiseComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetExpertise() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetArtisanLevel(FArtisanData& OutData) const;
    
};

