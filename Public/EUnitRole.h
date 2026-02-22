#pragma once
#include "CoreMinimal.h"
#include "EUnitRole.generated.h"

UENUM(BlueprintType)
enum class EUnitRole : uint8 {
    Husband,
    Wife,
    Son,
    Daughter,
    Retainer,
    Soldier,
    FreeMerchant,
    FreeLivestockMerchant,
    Deer,
    Chicken,
    Sheep,
    Lamb,
    Ox,
    Goat,
    Hound,
    Horse,
    Mule,
    BanditRecruit,
    None,
    Pig,
    Hare,
};

