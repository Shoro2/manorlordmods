#pragma once
#include "CoreMinimal.h"
#include "EParaRequirement.generated.h"

UENUM(BlueprintType)
enum class EParaRequirement : uint8 {
    None,
    RecipientPressedClaim,
    IPressedClaim,
    HaveEnoughFunds,
    NotHaveEnoughFunds,
};

