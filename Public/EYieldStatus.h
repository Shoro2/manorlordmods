#pragma once
#include "CoreMinimal.h"
#include "EYieldStatus.generated.h"

UENUM(BlueprintType)
enum class EYieldStatus : uint8 {
    None,
    Abysmal,
    Terrible,
    Poor,
    Average,
    Good,
    Great,
    Excellent,
    MAX,
};

