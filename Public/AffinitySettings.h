#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=DeveloperSettings -ObjectName=DeveloperSettings -FallbackName=DeveloperSettings
#include "EAffinityType.h"
#include "AffinitySettings.generated.h"

class UTexture2D;

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UAffinitySettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAffinityType, TSoftObjectPtr<UTexture2D>> Icons;
    
    UAffinitySettings();

};

