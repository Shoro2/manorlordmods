#pragma once
#include "CoreMinimal.h"
#include "ESquadType.generated.h"

UENUM(BlueprintType)
enum class ESquadType : uint8 {
    None,
    Militia,
    Mercenaries,
    Retinue,
    Bandits,
    Wildlife,
    Merchants,
};

