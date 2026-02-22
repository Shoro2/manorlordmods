#pragma once
#include "CoreMinimal.h"
#include "EPixelFedBackendId.generated.h"

UENUM(BlueprintType)
enum class EPixelFedBackendId : uint8 {
    Invalid,
    NoAA,
    FXAA,
    TAA,
    TSR,
    DLSS,
    FSR,
    XeSS,
    Switch2,
};

