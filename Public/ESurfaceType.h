#pragma once
#include "CoreMinimal.h"
#include "ESurfaceType.generated.h"

UENUM(BlueprintType)
enum class ESurfaceType : uint8 {
    Grass,
    DirtRoad,
    StoneRoad,
    Water,
    Building,
};

