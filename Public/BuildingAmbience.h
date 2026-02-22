#pragma once
#include "CoreMinimal.h"
#include "BuildingAmbience.generated.h"

class USoundBase;

USTRUCT(BlueprintType)
struct FBuildingAmbience {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 bType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USoundBase*> soundPool;
    
    MANORLORDS_API FBuildingAmbience();
};

