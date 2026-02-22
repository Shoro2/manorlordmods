#include "UnitSpawner.h"

AUnitSpawner::AUnitSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Enabled = false;
    this->ownedByRegion = false;
    this->Region = NULL;
    this->masterPtr = NULL;
    this->rows = 0;
    this->columns = 0;
    this->autoAssignToEnemy = false;
    this->DT_units = NULL;
    this->garrisonedIn = NULL;
    this->spawnCamped = false;
    this->allowBannerCarrier = false;
}

int32 AUnitSpawner::spawnUnits() {
    return 0;
}


