#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=DeveloperSettings -ObjectName=DeveloperSettings -FallbackName=DeveloperSettings
#include "ApprovalSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UApprovalSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ApprovalFactors[34];
    
    UApprovalSettings();

};

