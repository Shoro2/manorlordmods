#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=UserWidget -FallbackName=UserWidget
#include "Good.h"
#include "PlottedGood.h"
#include "ProductionGraphGenerator.h"
#include "Templates/SubclassOf.h"
#include "TrackedItem.h"
#include "RegionProductionPanel.generated.h"

class ARegion;
class UCanvasPanel;
class UDataTable;
class UGraphDataPoint;
class UImage;
class UProductionGraphLabel;
class UProductionPanelTooltip;
class UProductionSubsystem;
class URadioSelect;
class URegionProductionStockEntry;
class UVerticalBox;

UCLASS(Blueprintable, EditInlineNew)
class URegionProductionPanel : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<URegionProductionStockEntry> StockEntryWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UProductionGraphLabel> ProductionGraphLabelClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGraphDataPoint> GraphDataPointClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UProductionPanelTooltip> ToolTipClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* ItemsDataTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* StockEntriesBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URadioSelect* TimespanSelect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URadioSelect* CategorySelect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URadioSelect* GraphTypeSelect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* GraphCanvas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* GraphDataPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* GraphLines;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URadioSelect* ClearFilterButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProductionGraphGenerator GraphGenerator;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor CategoryColours[13];
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ARegion* Region;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UProductionSubsystem* ProductionSubsystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTrackedItem> TrackedItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPlottedGood> Plots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UUserWidget*> Labels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UUserWidget*> DataPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* ProductionPlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* ConsumptionPlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* BalancedPlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* StocksPlot;
    
public:
    URegionProductionPanel();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateXYLines(const FVector2D& InLocation, const bool IsOverGraph);
    
    UFUNCTION(BlueprintCallable)
    void SetupTestEntries();
    
    UFUNCTION(BlueprintCallable)
    void SetRegion(ARegion* inRegion);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnTrackStateChanged(const FGood& InGood, const bool InIsTracked);
    
    UFUNCTION(BlueprintCallable)
    void OnTimespanChanged(const FString& InValue);
    
    UFUNCTION(BlueprintCallable)
    void OnGraphTypeChanged(const FString& InValue);
    
    UFUNCTION(BlueprintCallable)
    void OnCategoryChanged(const FString& InValue);
    
    UFUNCTION(BlueprintCallable)
    void ClearFilters(const FString& InValue);
    
};

