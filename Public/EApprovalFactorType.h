#pragma once
#include "CoreMinimal.h"
#include "EApprovalFactorType.generated.h"

UENUM(BlueprintType)
enum class EApprovalFactorType : uint8 {
    hunger,
    starvation,
    cold,
    freezing,
    death,
    homelessness,
    missingMarketFood,
    missingMarketFirewood,
    missingMarketCloth,
    missingMarketLeather,
    noWaterAccess,
    missingChurch,
    foodVarietyGood,
    churchLevelGood,
    clothSuppliesGood,
    lowApproval,
    drinking,
    unemployment,
    patrols,
    administration,
    no_administration,
    hardship,
    missingEntertainment,
    unburied,
    taxation,
    NewFortune_BurgagePlotLv1Buff,
    FromTheAshes_ApprovalBuff,
    FromTheAshes_ApprovalAndInfluenceOnDeath,
    ApprovalOfTradeRoutes,
    ApprovalFromMilitiaEquipment,
    MissingMarketCommodities,
    MissingAmenities,
    SatisfiedMarketCommodities,
    SatisfiedAmenities,
    MAX,
};

