#pragma once
#include "CoreMinimal.h"
#include "UnitGroup.generated.h"

USTRUCT(BlueprintType)
struct FUnitGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> squads;
    
    MANORLORDS_API FUnitGroup();
};

