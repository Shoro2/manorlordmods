#include "RegionDevelopmentPerksPanel.h"

URegionDevelopmentPerksPanel::URegionDevelopmentPerksPanel() {
    this->PerkSlotIndex = 1;
    this->PerksContainer = NULL;
    this->TechDataTable = NULL;
    this->TranslatedTechDataTable = NULL;
    this->PerkEntryTemplate = NULL;
}

void URegionDevelopmentPerksPanel::UpdatePanel_Implementation(const FName InPerkName) {
}

void URegionDevelopmentPerksPanel::SetSelectedPerkName(const FName InPerkName) {
}

void URegionDevelopmentPerksPanel::SetRegion(ARegion* inRegion) {
}

void URegionDevelopmentPerksPanel::PerkSelectionAccepted() {
}

void URegionDevelopmentPerksPanel::OnPerkEntryHovered(const FName InPerkName) {
}

void URegionDevelopmentPerksPanel::OnPerkEntryClicked(const FName InPerkName) {
}

bool URegionDevelopmentPerksPanel::IsPerkActive(const FName& PerkName) const {
    return false;
}

FName URegionDevelopmentPerksPanel::GetSelectedPerkName() const {
    return NAME_None;
}

void URegionDevelopmentPerksPanel::GeneratePerks(const int32 SettlementLevel) {
}

void URegionDevelopmentPerksPanel::ConfirmPerkSelection_Implementation(const FName InPerkName) {
}


