#include "ResidentialRequirementSettings.h"

UResidentialRequirementSettings::UResidentialRequirementSettings() {
    this->UpgradeRequirementsPerLevel.AddDefaulted(5);
    this->TriggeringThresholdsPerLevel.AddDefaulted(1);
}

TArray<FName> UResidentialRequirementSettings::GetThingsSupplyingRequirement(const FRequirementCollection InCollection) {
    return TArray<FName>();
}

TSoftObjectPtr<UTexture2D> UResidentialRequirementSettings::GetIconForSupplyCategory(const EResidentialRequirement InSupplyCategory) {
    return NULL;
}

TArray<int32> UResidentialRequirementSettings::GetAllPossibleItemsForSupplyCategory(const EResidentialRequirement InSupplyCategory) {
    return TArray<int32>();
}


