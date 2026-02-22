#include "Plant.h"

FPlant::FPlant() {
    this->Type = ECropType::None;
    this->plowed = 0.00f;
    this->growth = 0.00f;
    this->InstanceId = 0;
    this->Rotation = 0.00f;
    this->typeBefore = ECropType::None;
    this->yield = 0;
    this->plantISM = NULL;
    this->plantISM_id = 0;
    this->bElevated = false;
    this->FertilityWhenPlantedQuant = 0;
}

