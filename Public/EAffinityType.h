#pragma once
#include "CoreMinimal.h"
#include "EAffinityType.generated.h"

UENUM(BlueprintType)
enum class EAffinityType : uint8 {
    Wilding,
    Apiation,
    Pollination,
    Pannage,
    Teeming,
    BarkGathering,
    LocalHandymen,
    None,
};

