#pragma once
#include "CoreMinimal.h"
#include "Diplo.generated.h"

class APawnCPP;

USTRUCT(BlueprintType)
struct FDiplo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APawnCPP* partner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Type;
    
    MANORLORDS_API FDiplo();
};

