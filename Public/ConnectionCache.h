#pragma once
#include "CoreMinimal.h"
#include "ConnectionCache.generated.h"

class ASMBuildingMaster;

USTRUCT(BlueprintType)
struct FConnectionCache {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* buildingA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* buildingB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool areConnectedByRoad;
    
    MANORLORDS_API FConnectionCache();
};

