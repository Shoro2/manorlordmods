#pragma once
#include "CoreMinimal.h"
#include "EDiploStatus.generated.h"

UENUM(BlueprintType)
enum class EDiploStatus : uint8 {
    Peace,
    War,
    Allies,
    Sovereign,
    Vassal,
};

