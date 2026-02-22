#pragma once
#include "CoreMinimal.h"
#include "ERoadMaterialType.generated.h"

UENUM(BlueprintType)
enum class ERoadMaterialType : uint8 {
    Default,
    Start,
    End,
    Short,
    Bridge,
};

