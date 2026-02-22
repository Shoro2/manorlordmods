#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=DeveloperSettings -ObjectName=DeveloperSettings -FallbackName=DeveloperSettings
#include "EPolicyType.h"
#include "PolicySettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UPolicySettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EPolicyType> BasePolicyTypes;
    
    UPolicySettings();

};

