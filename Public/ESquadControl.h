#pragma once
#include "CoreMinimal.h"
#include "ESquadControl.generated.h"

UENUM(BlueprintType)
enum class ESquadControl : uint8 {
    Full,
    Engaged,
    Partial,
    Fleeing,
    Encamped,
};

