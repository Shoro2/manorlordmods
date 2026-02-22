#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=DeveloperSettings -ObjectName=DeveloperSettings -FallbackName=DeveloperSettings
#include "EResidentialRequirement.h"
#include "RequirementCollection.h"
#include "RequirementsPerLevel.h"
#include "ResidentialRequirementSettings.generated.h"

class UTexture2D;

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UResidentialRequirementSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRequirementsPerLevel> UpgradeRequirementsPerLevel;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRequirementsPerLevel> TriggeringThresholdsPerLevel;
    
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> SupplyCategoryIcons[8];
    
public:
    UResidentialRequirementSettings();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FName> GetThingsSupplyingRequirement(const FRequirementCollection InCollection);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSoftObjectPtr<UTexture2D> GetIconForSupplyCategory(const EResidentialRequirement InSupplyCategory);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<int32> GetAllPossibleItemsForSupplyCategory(const EResidentialRequirement InSupplyCategory);
    
};

