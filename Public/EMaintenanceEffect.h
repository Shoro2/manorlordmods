#pragma once
#include "CoreMinimal.h"
#include "EMaintenanceEffect.generated.h"

UENUM(BlueprintType)
enum class EMaintenanceEffect : uint8 {
    NoEffect,
    InfluenceGain,
    InfluenceLoss,
    LaborSpeedIncrease,
    LaborSpeedDecrease,
    LaborSpeedDecreaseAndBotching,
    InjuryChance,
    CollapseChance,
    Botching,
    MAX,
};

