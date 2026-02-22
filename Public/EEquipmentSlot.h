#pragma once
#include "CoreMinimal.h"
#include "EEquipmentSlot.generated.h"

UENUM(BlueprintType)
enum class EEquipmentSlot : uint8 {
    Body,
    Weapon,
    Shield,
    Helmet,
    Accessory,
    Bonus,
    Head,
    None,
};

