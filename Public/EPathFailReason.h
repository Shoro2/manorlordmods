#pragma once
#include "CoreMinimal.h"
#include "EPathFailReason.generated.h"

UENUM(BlueprintType)
enum class EPathFailReason : uint8 {
    Unknown,
    NoSourceConnections,
    NoTargetConnections,
    NodeLimitReached,
    AllConnectionsChecked,
    InvalidTarget,
    InvalidSource,
};

