#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=DeveloperSettings -ObjectName=DeveloperSettings -FallbackName=DeveloperSettings
#include "CoatOfArmsData.h"
#include "CoatOfArmsSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UCoatOfArmsSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCoatOfArmsData baronData;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCoatOfArmsData> AIData;
    
    UCoatOfArmsSettings();

};

