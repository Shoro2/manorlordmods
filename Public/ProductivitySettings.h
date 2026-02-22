#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=DeveloperSettings -ObjectName=DeveloperSettings -FallbackName=DeveloperSettings
#include "EProductivityModifier.h"
#include "ProductivitySettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UProductivitySettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EProductivityModifier, int32> ProductivityModifierPercentValues;
    
    UProductivitySettings();

};

