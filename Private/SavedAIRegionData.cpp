#include "SavedAIRegionData.h"

FSavedAIRegionData::FSavedAIRegionData() {
    this->bBuiltStartingRoads = false;
    this->bMovedStartingBuildings = false;
    this->WeeklyTick = 0;
    this->UpdateNeededGoodsTick = 0;
    this->UpdateReservedGoodsTick = 0;
    this->SetCraftingAndProductionLimitsTick = 0;
    this->BuyMajorTradeRouteTick = 0;
    this->SetTradeRulesAndInventoryTargetsTick = 0;
    this->RedistributeWorkersTick = 0;
}

