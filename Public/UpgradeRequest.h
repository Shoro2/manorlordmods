#pragma once
#include "CoreMinimal.h"
#include "UpgradeRequest.generated.h"

class ASMBuildingMaster;

USTRUCT(BlueprintType)
struct FUpgradeRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* buildingMaster;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 upgradeID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Slot;
    
    MANORLORDS_API FUpgradeRequest();
};

