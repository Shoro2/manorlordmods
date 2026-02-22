#pragma once
#include "CoreMinimal.h"
#include "EAnimMode.generated.h"

UENUM(BlueprintType)
enum class EAnimMode : uint8 {
    Work,
    Combat,
    Mounted,
    Custom,
};

