#pragma once
#include "CoreMinimal.h"
#include "OpenClaim.generated.h"

class APawnCPP;
class ARegion;

USTRUCT(BlueprintType)
struct FOpenClaim {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARegion* Region;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 dayStarted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APawnCPP*> claimingPawns;
    
    MANORLORDS_API FOpenClaim();
};

