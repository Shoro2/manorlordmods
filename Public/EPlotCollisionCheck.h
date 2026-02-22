#pragma once
#include "CoreMinimal.h"
#include "EPlotCollisionCheck.generated.h"

UENUM(BlueprintType)
enum class EPlotCollisionCheck : uint8 {
    None,
    Left,
    Right,
    Either,
};

