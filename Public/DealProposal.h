#pragma once
#include "CoreMinimal.h"
#include "Diplo.h"
#include "DealProposal.generated.h"

class APawnCPP;

USTRUCT(BlueprintType)
struct FDealProposal {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APawnCPP* pawnA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APawnCPP* pawnB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDiplo> dealsA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDiplo> dealsB;
    
    MANORLORDS_API FDealProposal();
};

