#pragma once
#include "CoreMinimal.h"
#include "EResidentialRequirement.h"
#include "RequirementCollection.h"
#include "ResidentialRequirement.generated.h"

USTRUCT(BlueprintType)
struct FResidentialRequirement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRequirementCollection RequirementCollection;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 VarietyRequired;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EResidentialRequirement SupplyCategory;
    
    MANORLORDS_API FResidentialRequirement();
};

