#include "RegionDevelopmentEntry.h"

URegionDevelopmentEntry::URegionDevelopmentEntry() : UUserWidget(FObjectInitializer::Get()) {
    this->SettlementLevel = -1;
    this->SelectButton = NULL;
}

void URegionDevelopmentEntry::UpdateLockedState_Implementation(const int32 InCurrentRegionSettlementLevel) {
}

void URegionDevelopmentEntry::OnSelected() {
}


