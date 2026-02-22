#pragma once
#include "CoreMinimal.h"
#include "ResidentialRequirement.h"
#include "RequirementsPerLevel.generated.h"

USTRUCT(BlueprintType)
struct FRequirementsPerLevel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FResidentialRequirement> Requirements;
    
    MANORLORDS_API FRequirementsPerLevel();
};

