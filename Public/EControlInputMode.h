#pragma once
#include "CoreMinimal.h"
#include "EControlInputMode.generated.h"

UENUM(BlueprintType)
enum class EControlInputMode : uint8 {
    MouseKeyboard,
    Gamepad,
    Touch,
};

