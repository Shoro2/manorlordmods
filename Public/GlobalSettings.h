#pragma once
#include "CoreMinimal.h"
#include "GlobalSettings.generated.h"

USTRUCT(BlueprintType)
struct FGlobalSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool snapToRoads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool snapToBuildings;
    
    MANORLORDS_API FGlobalSettings();
};

