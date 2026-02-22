#include "ProductionTrackerSettings.h"

UProductionTrackerSettings::UProductionTrackerSettings() {
    this->productionTimeCategories.AddDefaulted(5);
    this->ExcellentYieldStatusValue = 175;
    this->GreatYieldStatusValue = 150;
    this->GoodYieldStatusValue = 125;
    this->AverageYieldStatusValue = 75;
    this->PoorYieldStatusValue = 50;
    this->TerribleYieldStatusValue = 25;
}


