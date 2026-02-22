#pragma once
#include "CoreMinimal.h"
#include "ProductionTrackerEntry.h"
#include "SavedProductionEntry.generated.h"

USTRUCT(BlueprintType)
struct FSavedProductionEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FProductionTrackerEntry> productionTrackerEntries;
    
    MANORLORDS_API FSavedProductionEntry();
};

