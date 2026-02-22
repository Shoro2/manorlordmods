#include "MaintenanceComponent.h"

UMaintenanceComponent::UMaintenanceComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UMaintenanceComponent::SetSliderValue(const int32 InSliderValue) {
}

TArray<FMaintenanceTypes> UMaintenanceComponent::GetTrackedMaintenanceTypes() const {
    return TArray<FMaintenanceTypes>();
}

EMaintenanceSliderValue UMaintenanceComponent::GetSliderValueAsEnum() const {
    return EMaintenanceSliderValue::Half;
}

int32 UMaintenanceComponent::GetSliderValue() const {
    return 0;
}

EMaintenanceStatus UMaintenanceComponent::GetMaintenanceStatusForTypes(const FMaintenanceTypes& InMaintenanceTypes) const {
    return EMaintenanceStatus::NoMaintenanceNeeded;
}

EMaintenanceStatus UMaintenanceComponent::GetMaintenanceStatus() const {
    return EMaintenanceStatus::NoMaintenanceNeeded;
}

float UMaintenanceComponent::GetMaintenancePercentage(const FMaintenanceTypes& InMaintenanceTypes) const {
    return 0.0f;
}

int32 UMaintenanceComponent::GetMaintenanceDurationInDays(const FMaintenanceTypes& InMaintenanceTypes) const {
    return 0;
}

FMaintenanceSupply UMaintenanceComponent::GetMaintenanceDataForGoodTypes(const FMaintenanceTypes& InMaintenanceTypes, const bool bReturnValueWithModifiers, const bool bIncludeSliderModifier) const {
    return FMaintenanceSupply{};
}

float UMaintenanceComponent::GetFinalMaintenanceRateModifierValue(const bool bIncludeFrequencyModifier) const {
    return 0.0f;
}

TArray<FMaintenanceTypes> UMaintenanceComponent::GetDynamicMaintenanceTypes() const {
    return TArray<FMaintenanceTypes>();
}

TMap<EMaintenanceCombo, EMaintenanceEffect> UMaintenanceComponent::GetDynamicMaintenanceEffects() const {
    return TMap<EMaintenanceCombo, EMaintenanceEffect>();
}

TArray<FMaintenanceSupply> UMaintenanceComponent::GetDynamicMaintenanceData() const {
    return TArray<FMaintenanceSupply>();
}

int32 UMaintenanceComponent::GetDaysRemainingUntilMaintenanceRequired(const FMaintenanceTypes& InMaintenanceTypes) const {
    return 0;
}

TMap<EMaintenanceRateModifier, int32> UMaintenanceComponent::GetAdditionalMaintenanceRateModifiersInPercents(bool bIncludeSliderEffect) const {
    return TMap<EMaintenanceRateModifier, int32>();
}

EMaintenanceEffect UMaintenanceComponent::GetActiveMaintenanceEffect() const {
    return EMaintenanceEffect::NoEffect;
}

bool UMaintenanceComponent::DoesBuildingNeedMaintaining() const {
    return false;
}


