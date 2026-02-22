#pragma once
#include "CoreMinimal.h"
#include "EGroundCoverCategory.generated.h"

UENUM(BlueprintType)
enum class EGroundCoverCategory : uint8 {
    Generic,
    Field,
    Forest,
    ForestEdge,
    Dirt,
    FieldAndEdge,
    River,
    Rural,
    Urban,
    Farmland,
};

