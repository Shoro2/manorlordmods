#pragma once
#include "CoreMinimal.h"
#include "LordSetupData.h"
#include "GameSetupMapData.generated.h"

USTRUCT(BlueprintType)
struct FGameSetupMapData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLordSetupData> AILordData;
    
    MANORLORDS_API FGameSetupMapData();
};

