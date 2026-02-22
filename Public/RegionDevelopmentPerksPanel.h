#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=SystemCore -ObjectName=NaviSubGrid -FallbackName=NaviSubGrid
#include "Templates/SubclassOf.h"
#include "RegionDevelopmentPerksPanel.generated.h"

class ARegion;
class UDataTable;
class URegionDevelopmentPerkEntry;
class UWrapBox;

UCLASS(Blueprintable, EditInlineNew)
class URegionDevelopmentPerksPanel : public UNaviSubGrid {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PerkSlotIndex;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWrapBox* PerksContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* TechDataTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* TranslatedTechDataTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<URegionDevelopmentPerkEntry> PerkEntryTemplate;
    
public:
    URegionDevelopmentPerksPanel();

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdatePanel(const FName InPerkName);
    
    UFUNCTION(BlueprintCallable)
    void SetSelectedPerkName(const FName InPerkName);
    
    UFUNCTION(BlueprintCallable)
    void SetRegion(ARegion* inRegion);
    
    UFUNCTION(BlueprintCallable)
    void PerkSelectionAccepted();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnPerkEntryHovered(const FName InPerkName);
    
    UFUNCTION(BlueprintCallable)
    void OnPerkEntryClicked(const FName InPerkName);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPerkActive(const FName& PerkName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetSelectedPerkName() const;
    
public:
    UFUNCTION(BlueprintCallable)
    void GeneratePerks(const int32 SettlementLevel);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ConfirmPerkSelection(const FName InPerkName);
    
};

