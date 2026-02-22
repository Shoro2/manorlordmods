#pragma once
#include "CoreMinimal.h"
#include "EPolicyType.generated.h"

UENUM()
enum class EPolicyType : uint32 {
    Unknown,
    HuntingGround = 2,
    NightWatch = 4,
    BathhousePleasure = 7,
    WeeklyMass,
    CleanWater = 10,
    StrictFasting = 12,
    Coinage = 15,
    GuildBrotherhood,
    PublicWeaponBan,
    PurchasePrivilage,
};

