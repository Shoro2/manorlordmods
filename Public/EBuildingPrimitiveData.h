#pragma once
#include "CoreMinimal.h"
#include "EBuildingPrimitiveData.generated.h"

UENUM(BlueprintType)
enum class EBuildingPrimitiveData : uint8 {
    ColorA,
    ColorB,
    StallRollout,
    MarketHighlight,
    UnemploymentCull,
    TargetHighlightTime,
    Colliding,
    MarketHighlightTintValue,
    MarketHighlightTime,
    SeeThroughLevel,
    CorrectionLeftSideX = 12,
    CorrectionLeftSideY,
    CorrectionRightSideX,
    CorrectionRightSideY,
    WallNormalLeftX,
    WallNormalLeftY,
    WallNormalRightX,
    WallNormalRightY,
    MarketTextureTopLeft,
    MarketTextureTopRight,
    MarketTextureBottomRight = MarketTextureTopRight,
    MarketTextureBottomLeft,
};

