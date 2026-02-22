#pragma once
#include "CoreMinimal.h"
#include "TrackedItem.generated.h"

class URegionProductionStockEntry;

USTRUCT(BlueprintType)
struct FTrackedItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URegionProductionStockEntry* Entry;
    
    MANORLORDS_API FTrackedItem();
};

