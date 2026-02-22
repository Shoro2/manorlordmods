#include "UnitTemplate.h"

FUnitTemplate::FUnitTemplate() {
    this->Icon = 0;
    this->iconTexture = NULL;
    this->isMilitia = false;
    this->cost = 0.00f;
    this->hideHeads = false;
    this->card = NULL;
    this->Portrait = NULL;
    this->MaxSize = 0;
    this->minMeleeTraining = 0.00f;
    this->minArcheryTraining = 0.00f;
    this->minHouseLv = 0;
    this->hasBannerCarrier = false;
    this->concealmentLevel = 0;
    this->combatExperience = 0.00f;
}

