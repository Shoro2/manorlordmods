#pragma once
#include "CoreMinimal.h"
#include "ENodeType.generated.h"

UENUM()
enum class ENodeType : uint32 {
    None,
    Salt,
    Iron,
    Clay,
    Deer,
    Fish,
    Berries,
    Stone,
    Ladders,
    Mushrooms,
    SmallGame,
    Eel,
    Fertility,
};

