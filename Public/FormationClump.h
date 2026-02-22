#pragma once
#include "CoreMinimal.h"
#include "FormationClump.generated.h"

USTRUCT(BlueprintType)
struct FFormationClump {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> squads;
    
    MANORLORDS_API FFormationClump();
};

