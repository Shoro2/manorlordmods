#pragma once
#include "CoreMinimal.h"
#include "EIoFileCategory.generated.h"

UENUM(BlueprintType)
enum class EIoFileCategory : uint8 {
    None,
    MapSave,
    ImageLarge,
    ImageSmall,
    PlayerProfile,
    Descriptor,
};

