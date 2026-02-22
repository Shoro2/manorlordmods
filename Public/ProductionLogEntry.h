#pragma once
#include "CoreMinimal.h"
#include "LogDate.h"
#include "ProductionLogEntry.generated.h"

USTRUCT(BlueprintType)
struct FProductionLogEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, int32> EndOfLogTotals;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, int32> Produced;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, int32> Consumed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLogDate Timestamp;
    
public:
    MANORLORDS_API FProductionLogEntry();
};

