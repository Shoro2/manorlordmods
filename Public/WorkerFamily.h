#pragma once
#include "CoreMinimal.h"
#include "ConsumptionStatus.h"
#include "WorkerFamily.generated.h"

class ASMBuildingMaster;
class ASMUnit;

USTRUCT(BlueprintType)
struct FWorkerFamily {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> familyMembers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* assignedTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* familyStall;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* familyHome;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConsumptionStatus ConsumptionStatus;
    
    MANORLORDS_API FWorkerFamily();
};

