#pragma once
#include "CoreMinimal.h"
#include "EQueuedUIUpdateType.h"
#include "QueuedUIUpdate.generated.h"

class ARegion;

USTRUCT(BlueprintType)
struct FQueuedUIUpdate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARegion* Region;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQueuedUIUpdateType UpdateType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 goodType;
    
    MANORLORDS_API FQueuedUIUpdate();
};

