#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=IntPoint -FallbackName=IntPoint
//CROSS-MODULE INCLUDE V2: -ModuleName=DeveloperSettings -ObjectName=DeveloperSettings -FallbackName=DeveloperSettings
#include "ECropType.h"
#include "CropSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UCropSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseDailyGrowthRate[15];
    
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BaseYieldPer100Plants[15];
    
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint HarvestSeason[15];
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HarvestGrowthThreshold;
    
    UCropSettings();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsHarvestSeasonal(ECropType InCropType);
    
};

