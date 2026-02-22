#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=SystemCore -ObjectName=NaviSubGrid -FallbackName=NaviSubGrid
#include "OnSettlementLevelSelectedDelegate.h"
#include "RegionDevelopmentPanel.generated.h"

class ARegion;
class URegionDevelopmentEntry;

UCLASS(Blueprintable, EditInlineNew)
class URegionDevelopmentPanel : public UNaviSubGrid {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSettlementLevelSelected OnSettlementLevelSelected;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URegionDevelopmentEntry* ClickedEntry;
    
public:
    URegionDevelopmentPanel();

    UFUNCTION(BlueprintCallable)
    void UpdateAllEntryLockedStates();
    
    UFUNCTION(BlueprintCallable)
    void SetRegion(ARegion* inRegion);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnEntrySelected(const int32 InSettlementLevel);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARegion* GetRegion() const;
    
};

