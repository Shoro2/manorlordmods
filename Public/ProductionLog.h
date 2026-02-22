#pragma once
#include "CoreMinimal.h"
#include "ProductionLogEntry.h"
#include "ProductionLog.generated.h"

class ARegion;

USTRUCT(BlueprintType)
struct FProductionLog {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName regionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ARegion* SourceRegion;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FProductionLogEntry> EntriesForRegion;
    
public:
    MANORLORDS_API FProductionLog();
};

