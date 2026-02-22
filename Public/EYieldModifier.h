#pragma once
#include "CoreMinimal.h"
#include "EYieldModifier.generated.h"

UENUM(BlueprintType)
enum class EYieldModifier : uint8 {
    None,
    Perk_Smallholdings,
    Perk_FarmingYieldPenalty,
    Perk_SkilledWoodworkers,
    Perk_BlacksmithYieldIncrease,
    Perk_LivestockYieldPenalty,
    Perk_IncreasedHunterYield,
    Perk_ImprovedStonemasonsStation,
    Perk_ArmorerArtisanBuff,
    Perk_EfficientElevationFarming,
    Perk_ArtisanEfficiencyPenalty,
    Policy_HuntingGrounds,
    Affinity_Pollination,
    Affinity_Pannage,
    Affinity_BarkGathering,
};

