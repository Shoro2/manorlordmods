#include "SavedBuilding.h"

FSavedBuilding::FSavedBuilding() {
    this->localHp = 0.00f;
    this->bType = 0;
    this->artisanJob = 0;
    this->cropType = ECropType::None;
    this->cropType2 = ECropType::None;
    this->cropType3 = ECropType::None;
    this->bRotateCrops = false;
    this->onFire = false;
    this->fireAmt = 0.00f;
    this->paused = false;
    this->isBeingUpgraded = false;
    this->activeWorkers = 0;
    this->activeOxen = 0;
    this->fieldWorkersNeeded = 0;
    this->Priority = 0;
    this->forceHarvest = false;
    this->productionFocus = 0;
    this->needsRefueling = false;
    this->refueled = false;
    this->refuelDay = 0;
    this->stockFuelFor = 0;
    this->ActiveSliderValue = 0;
    this->huntingLimit = 0;
    this->wasFullyConstructed = false;
    this->workAreaLimited = false;
    this->workAreaRange = 0.00f;
    this->bProtectResourceArea = false;
    this->houseVariety = 0;
    this->houseVarietyBPart = 0;
    this->ownerPawnID = 0;
    this->muleTrain_buyingType = 0;
    this->muleTrain_sellingType = 0;
    this->typeBeforeChange = 0;
    this->mourningPeriod = 0;
    this->allowMarketStalls = false;
    this->overstocking = 0;
    this->PassiveYieldLastDay = 0;
    this->ByproductProgress = 0;
    this->DayConstructionFinished = 0;
}

