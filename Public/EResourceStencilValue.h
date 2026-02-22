#pragma once
#include "CoreMinimal.h"
#include "EResourceStencilValue.generated.h"

UENUM(BlueprintType)
enum class EResourceStencilValue : uint8 {
    None,
    Highlight = 254,
    Collides = 253,
};

