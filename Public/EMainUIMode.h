#pragma once
#include "CoreMinimal.h"
#include "EMainUIMode.generated.h"

UENUM(BlueprintType)
enum class EMainUIMode : uint8 {
    Gameplay,
    Cinematics,
    GameSummary,
    PhotoMode,
};

