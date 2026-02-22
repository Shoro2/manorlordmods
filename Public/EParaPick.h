#pragma once
#include "CoreMinimal.h"
#include "EParaPick.generated.h"

UENUM(BlueprintType)
enum class EParaPick : uint8 {
    None,
    MyRegion,
    OthersRegion,
    FreeRegion,
    Resource,
    OthersClaim,
    Amt,
    Time,
};

