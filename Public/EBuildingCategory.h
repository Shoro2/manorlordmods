#pragma once
#include "CoreMinimal.h"
#include "EBuildingCategory.generated.h"

UENUM(BlueprintType)
enum class EBuildingCategory : uint8 {
    Gathering,
    Logistics,
    Residential,
    Farming,
    Industry,
    Military,
    Cosmetic,
};

