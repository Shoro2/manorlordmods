#include "VillageSpawner.h"

AVillageSpawner::AVillageSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CanBePlayer = false;
    this->AIOnly = false;
    this->bailiff = false;
    this->ironDeposit = false;
    this->farmingVillage = false;
    this->woodcutterVillage = false;
    this->banditCamp = false;
    this->stoneQuarry = false;
    this->Deer = false;
    this->Tradepoint = false;
    this->stoneResources = false;
    this->beeResources = false;
    this->saltDeposit = false;
    this->clayDeposit = false;
    this->berries = false;
    this->shrooms = false;
    this->numResources = 0;
    this->Region = NULL;
    this->masterPtr = NULL;
    this->pointsSpawned = 0;
    this->ensureOption = 0;
}

void AVillageSpawner::calculateOptions() {
}


