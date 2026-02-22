#include "PerkComponent.h"

UPerkComponent::UPerkComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UPerkComponent::IsPerkSlotUnlocked(const uint8 InPerkSlotIndex, const URegionDevelopmentEntry* RegionDevelopmentEntry) const {
    return false;
}

FName UPerkComponent::GetPerkForPerkEffectByString(const FString& InPerkEffect) {
    return NAME_None;
}

FName UPerkComponent::GetPerkForPerkEffect(const EPerkEffect InPerkEffect) {
    return NAME_None;
}

FName UPerkComponent::GetActivePerkInSlot(const int32 SlotIndex) {
    return NAME_None;
}


