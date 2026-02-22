#pragma once
#include "CoreMinimal.h"
#include "EResidentialRequirement.generated.h"

UENUM(BlueprintType)
enum class EResidentialRequirement : uint8 {
    Water,
    Food,
    Fuel,
    Commodities,
    Fun,
    Faith,
    Amenities,
    Missing,
    MAX,
};

