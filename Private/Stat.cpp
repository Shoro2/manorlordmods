#include "Stat.h"

FStat::FStat() {
    this->bWorkInProgress = false;
    this->purposeIcon = NULL;
    this->BuildingCategory = EBuildingCategory::Gathering;
    this->SFX = NULL;
    this->isPlaza = false;
    this->bSize = 0.00f;
    this->bCircularBorder = false;
    this->isWork = false;
    this->job = 0;
    this->garrisonLimit = 0;
    this->pastureSpace = 0;
    this->stableSpace = 0;
    this->shelter = false;
    this->buildingFunction = EBuildingFunction::Default;
    this->maxHp = 0;
    this->Range = 0.00f;
    this->rangeType = 0.00f;
    this->needsRoad = false;
    this->collidesWithRoads = false;
    this->canRelocate = false;
    this->upgradedFrom = 0;
    this->canSetWorkArea = false;
    this->chooseProducedGood = false;
    this->smells = false;
    this->flammable = false;
    this->bProximityCollapse = false;
    this->bCanGarrisonIn = false;
    this->LaborBenchmark = 0;
    this->AreGoodsSeasonal = false;
    this->accidentRate = 0;
    this->deathRate = 0;
    this->deathFromCollapseRate = 0;
    this->constructionCost = 0;
    this->maxInRegion = 0;
    this->SettlementLevel = 0;
    this->AIcanBuild = false;
    this->storageLimitGeneric = 0;
    this->storageLimitLarge = 0;
    this->storageLimitPantry = 0;
    this->spoilageRateReduction = 0.00f;
    this->moduleCategory = EModuleCategory::None;
    this->isModule = false;
    this->placedWithin = 0;
}

