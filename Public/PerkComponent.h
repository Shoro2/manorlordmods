#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "EPerkEffect.h"
#include "PerkComponent.generated.h"

class UPerkSettings;
class URegionDevelopmentEntry;

UCLASS(Blueprintable, ClassGroup=Custom, Within=Region, meta=(BlueprintSpawnableComponent))
class UPerkComponent : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPerkSettings* PerkSettings;
    
public:
    UPerkComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPerkSlotUnlocked(const uint8 InPerkSlotIndex, const URegionDevelopmentEntry* RegionDevelopmentEntry) const;
    
    UFUNCTION(BlueprintCallable)
    static FName GetPerkForPerkEffectByString(const FString& InPerkEffect);
    
    UFUNCTION(BlueprintCallable)
    static FName GetPerkForPerkEffect(const EPerkEffect InPerkEffect);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetActivePerkInSlot(const int32 SlotIndex);
    
};

