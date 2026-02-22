#pragma once
#include "CoreMinimal.h"
#include "TradeDestination.generated.h"

class ASMBuildingMaster;

USTRUCT(BlueprintType)
struct FTradeDestination {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* building;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 goodType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool buying;
    
    MANORLORDS_API FTradeDestination();
};

