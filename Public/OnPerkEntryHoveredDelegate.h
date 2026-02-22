#pragma once
#include "CoreMinimal.h"
#include "OnPerkEntryHoveredDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPerkEntryHovered, const FName, InPerkType);

