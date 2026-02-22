#include "ProductionTrackerComponent.h"

UProductionTrackerComponent::UProductionTrackerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DateCreated = 0;
    this->weatherMasterPtr = NULL;
}

void UProductionTrackerComponent::setWeatherMasterPtr(AWeatherMaster* inWeatherMasterPtr) {
}

EYieldStatus UProductionTrackerComponent::GetYieldStatus() const {
    return EYieldStatus::None;
}

float UProductionTrackerComponent::GetTotalTime() const {
    return 0.0f;
}

TArray<int32> UProductionTrackerComponent::GetTimePercentagesForAllCategories() {
    return TArray<int32>();
}

int32 UProductionTrackerComponent::GetTimePercentageForSpecificCategory(const EProductionCategory InCategory) {
    return 0;
}

TArray<FProductionTimeEntry> UProductionTrackerComponent::getTimeEntries() {
    return TArray<FProductionTimeEntry>();
}

int32 UProductionTrackerComponent::GetNumberOfGoodTypesInLog() {
    return 0;
}

TMap<int32, int32> UProductionTrackerComponent::getGoodsProducedOver(const int64 NumDays) const {
    return TMap<int32, int32>();
}

TArray<FProductionTrackerEntry> UProductionTrackerComponent::GetEntriesOfItemType(const int32 ItemType) {
    return TArray<FProductionTrackerEntry>();
}

int64 UProductionTrackerComponent::ageOfBuildingInDays() const {
    return 0;
}


