#pragma once
#include "CoreMinimal.h"
#include "ECropType.generated.h"

UENUM(BlueprintType)
enum class ECropType : uint8 {
    None,
    Wheat,
    Flax,
    Barley,
    Brushwood,
    Vegetables,
    AnimalTraps,
    Rye,
    Herbs,
    Apples,
    Carrots,
    Cabbages,
    Beetroots,
    Pears,
    Quinces,
    MAX,
};

