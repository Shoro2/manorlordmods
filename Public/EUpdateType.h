#pragma once
#include "CoreMinimal.h"
#include "EUpdateType.generated.h"

UENUM(BlueprintType)
enum class EUpdateType : uint8 {
    General,
    Construction,
    FinishedConstruction,
    UpgradedBuilding,
    InventoryChange,
    OnFire,
};

