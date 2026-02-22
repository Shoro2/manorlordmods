#pragma once
#include "CoreMinimal.h"
#include "EMaintenanceRateModifier.generated.h"

UENUM(BlueprintType)
enum class EMaintenanceRateModifier : uint8 {
    Affinity_LocalHandymen,
    MaintenanceRate_Half,
    MaintenanceRate_Double,
    Perk_ImprovedMineMaintenance,
};

