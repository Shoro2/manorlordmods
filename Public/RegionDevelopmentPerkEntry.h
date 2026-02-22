#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=UserWidget -FallbackName=UserWidget
#include "OnPerkEntryClickedDelegate.h"
#include "OnPerkEntryHoveredDelegate.h"
#include "RegionDevelopmentPerkEntry.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URegionDevelopmentPerkEntry : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPerkEntryHovered OnPerkEntryHovered;
    
    UPROPERTY(BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPerkEntryClicked OnPerkEntryClicked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PerkToApply;
    
    URegionDevelopmentPerkEntry();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitialiseFromType(const FName InPerkName);
    
};

