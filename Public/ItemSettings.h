#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=DeveloperSettings -ObjectName=DeveloperSettings -FallbackName=DeveloperSettings
#include "EItemCategory.h"
#include "EItemSubcategory.h"
#include "ItemSettings.generated.h"

class UTexture2D;

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UItemSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> ItemSubcategoryCategoryIcons[28];
    
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> ItemCategoryIcons[13];
    
    UItemSettings();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSoftObjectPtr<UTexture2D> GetIconForItemSubcategory(const EItemSubcategory InSubcategory);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSoftObjectPtr<UTexture2D> GetIconForItemCategory(const EItemCategory InCategory);
    
};

