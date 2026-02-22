#pragma once
#include "CoreMinimal.h"
#include "EProductionCategory.generated.h"

UENUM(BlueprintType)
enum class EProductionCategory : uint8 {
    None,
    Labor,
    Transportation,
    Rest,
    Extensions,
    Illness,
    Waiting,
    Militia,
};

