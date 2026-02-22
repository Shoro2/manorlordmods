#pragma once
#include "CoreMinimal.h"
#include "EStorageType.generated.h"

UENUM(BlueprintType)
enum class EStorageType : uint8 {
    Generic,
    Large,
    Pantry,
    Hidden,
    Any,
    Tavern,
    Church,
    Water,
};

