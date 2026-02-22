#pragma once
#include "CoreMinimal.h"
#include "SavedAIData.generated.h"

USTRUCT(BlueprintType)
struct FSavedAIData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LastTickDay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool builtStartingRoads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool movedStartingBuildings;
    
    MANORLORDS_API FSavedAIData();
};

