#pragma once
#include "CoreMinimal.h"
#include "ECinematicEvent.generated.h"

UENUM(BlueprintType)
enum class ECinematicEvent : uint8 {
    Continue,
    GoToSummary,
};

