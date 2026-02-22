#pragma once
#include "CoreMinimal.h"
#include "EWIPStatus.generated.h"

UENUM(BlueprintType)
enum class EWIPStatus : uint8 {
    Full,
    Partial,
    Broken,
    ToDo,
};

