#include "RegionProductionPanel.h"

URegionProductionPanel::URegionProductionPanel() : UUserWidget(FObjectInitializer::Get()) {
    this->StockEntryWidgetClass = NULL;
    this->ProductionGraphLabelClass = NULL;
    this->GraphDataPointClass = NULL;
    this->ToolTipClass = NULL;
    this->ItemsDataTable = NULL;
    this->StockEntriesBox = NULL;
    this->TimespanSelect = NULL;
    this->CategorySelect = NULL;
    this->GraphTypeSelect = NULL;
    this->GraphCanvas = NULL;
    this->GraphDataPoints = NULL;
    this->GraphLines = NULL;
    this->ClearFilterButton = NULL;
    this->Region = NULL;
    this->ProductionSubsystem = NULL;
    this->ProductionPlot = NULL;
    this->ConsumptionPlot = NULL;
    this->BalancedPlot = NULL;
    this->StocksPlot = NULL;
}

void URegionProductionPanel::UpdateXYLines_Implementation(const FVector2D& InLocation, const bool IsOverGraph) {
}

void URegionProductionPanel::SetupTestEntries() {
}

void URegionProductionPanel::SetRegion(ARegion* inRegion) {
}

void URegionProductionPanel::OnTrackStateChanged(const FGood& InGood, const bool InIsTracked) {
}

void URegionProductionPanel::OnTimespanChanged(const FString& InValue) {
}

void URegionProductionPanel::OnGraphTypeChanged(const FString& InValue) {
}

void URegionProductionPanel::OnCategoryChanged(const FString& InValue) {
}

void URegionProductionPanel::ClearFilters(const FString& InValue) {
}


