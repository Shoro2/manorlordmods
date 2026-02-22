#pragma once
#include "CoreMinimal.h"
#include "EItemCategory.generated.h"

UENUM(BlueprintType)
enum class EItemCategory : uint8 {
    None,
    Construction,
    Food,
    Material,
    Commodity,
    Livestock,
    Military,
    Crop,
    Transitionary,
    Special,
    Fuel,
    Siege,
    Recipe,
    MAX,
};

