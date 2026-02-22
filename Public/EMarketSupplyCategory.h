#pragma once
#include "CoreMinimal.h"
#include "EMarketSupplyCategory.generated.h"

UENUM(BlueprintType)
enum class EMarketSupplyCategory : uint8 {
    Fuel,
    Food,
    Fabrics,
    Clothing,
};

