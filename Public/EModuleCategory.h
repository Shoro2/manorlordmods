#pragma once
#include "CoreMinimal.h"
#include "EModuleCategory.generated.h"

UENUM(BlueprintType)
enum class EModuleCategory : uint8 {
    None,
    Market,
    Manor,
    Monastery,
};

