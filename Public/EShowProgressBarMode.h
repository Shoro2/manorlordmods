#pragma once
#include "CoreMinimal.h"
#include "EShowProgressBarMode.generated.h"

UENUM(BlueprintType)
enum class EShowProgressBarMode : uint8 {
    AlwaysShow,
    OnlyLvlUp,
    Never,
};

