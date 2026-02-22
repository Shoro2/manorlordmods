#pragma once
#include "CoreMinimal.h"
#include "EObjectiveType.generated.h"

UENUM(BlueprintType)
enum class EObjectiveType : uint8 {
    None,
    Survive,
    HaveBuildings,
    HavePopulation,
    HaveNumFamilies,
    HaveSurplus,
    GainSurplus,
    HaveRegionalWealth,
    SendParagraph,
    ControlRegion,
    PayMercenaries,
    PayKingsTax,
    WinBattle,
    HaveUpgrades,
    HaveTreasury,
    RequirementFilledNumPlots,
    HaveFamiliesEmployedAtBuildingTypes,
    HaveFamiliesLivingInBuildingTypes,
    HaveMarketAvailabilityOfGoods,
};

