#pragma once
#include "CoreMinimal.h"
#include "ELocomotionStance.generated.h"

UENUM(BlueprintType)
enum class ELocomotionStance : uint8 {
    Default,
    Tool,
    SwordAndShield,
    SpearAndShield,
    TwoHandedWeapon,
    Bow,
    Crossbow,
    FishingRod,
    Cane,
    Bag,
    Handcart,
    Box,
    Bucket,
    Banner,
    BackBasket,
};

