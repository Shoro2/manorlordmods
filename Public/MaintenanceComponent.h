#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "EMaintenanceCombo.h"
#include "EMaintenanceEffect.h"
#include "EMaintenanceRateModifier.h"
#include "EMaintenanceSliderValue.h"
#include "EMaintenanceStatus.h"
#include "MaintenanceSupply.h"
#include "MaintenanceTypes.h"
#include "MaintenanceComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMaintenanceComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UMaintenanceComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetSliderValue(const int32 InSliderValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FMaintenanceTypes> GetTrackedMaintenanceTypes() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EMaintenanceSliderValue GetSliderValueAsEnum() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSliderValue() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EMaintenanceStatus GetMaintenanceStatusForTypes(const FMaintenanceTypes& InMaintenanceTypes) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EMaintenanceStatus GetMaintenanceStatus() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaintenancePercentage(const FMaintenanceTypes& InMaintenanceTypes) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaintenanceDurationInDays(const FMaintenanceTypes& InMaintenanceTypes) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FMaintenanceSupply GetMaintenanceDataForGoodTypes(const FMaintenanceTypes& InMaintenanceTypes, const bool bReturnValueWithModifiers, const bool bIncludeSliderModifier) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFinalMaintenanceRateModifierValue(const bool bIncludeFrequencyModifier) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FMaintenanceTypes> GetDynamicMaintenanceTypes() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<EMaintenanceCombo, EMaintenanceEffect> GetDynamicMaintenanceEffects() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FMaintenanceSupply> GetDynamicMaintenanceData() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetDaysRemainingUntilMaintenanceRequired(const FMaintenanceTypes& InMaintenanceTypes) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<EMaintenanceRateModifier, int32> GetAdditionalMaintenanceRateModifiersInPercents(bool bIncludeSliderEffect) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EMaintenanceEffect GetActiveMaintenanceEffect() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DoesBuildingNeedMaintaining() const;
    
};

