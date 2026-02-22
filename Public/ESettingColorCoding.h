#pragma once
#include "CoreMinimal.h"
#include "ESettingColorCoding.generated.h"

UENUM(BlueprintType)
enum class ESettingColorCoding : uint8 {
    RandomColors,
    PlayerCoded,
};

