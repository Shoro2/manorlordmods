#pragma once
#include "CoreMinimal.h"
#include "EProductivityModifier.generated.h"

UENUM(BlueprintType)
enum class EProductivityModifier : uint8 {
    None,
    CraftingSpeed_Perk_MiningCraftingSpeedMalus,
    CraftingSpeed_Perk_ImprovedStonemasonsStation,
    CraftingSpeed_Perk_HuntingAndFishingProductivityPenalty,
    CraftingSpeed_Perk_MiningSpeedIncrease,
    CraftingSpeed_Perk_ImprovedStoneGathering,
    WalkingSpeed_Perk_OxHandlerSpeedBuff,
    CraftingSpeed_Maintenance_Failed,
    CraftingSpeed_Maintenance_Half,
    CraftingSpeed_Maintenance_Double,
};

