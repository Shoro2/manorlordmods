#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=DeveloperSettings -ObjectName=DeveloperSettings -FallbackName=DeveloperSettings
#include "EMaintenanceEffect.h"
#include "MaintenanceSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UMaintenanceSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaintenancePendingDays;
    
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaintenanceEffectRatesInPercents[9];
    
    UMaintenanceSettings();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaintenanceEffectValue(EMaintenanceEffect InEffect) const;
    
};

