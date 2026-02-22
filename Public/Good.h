#pragma once
#include "CoreMinimal.h"
#include "Good.generated.h"

class ASMBuildingMaster;
class ASMUnit;

USTRUCT(BlueprintType)
struct FGood {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 amt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* belongsTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMUnit* belongsToUnit;
    
    MANORLORDS_API FGood();
};

