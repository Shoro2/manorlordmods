#include "SavedSquad.h"

FSavedSquad::FSavedSquad() {
    this->squadType = ESquadType::None;
    this->Icon = 0;
    this->ctrlGroup = 0;
    this->MaxSize = 0;
    this->ID = 0;
    this->targetSquadID = 0;
    this->targetSquad = 0;
    this->splitFromSquad = 0;
    this->arrivesIn = 0;
    this->payDay = 0;
    this->companyID = 0;
    this->spread = 0.00f;
    this->avgPotential = 0.00f;
    this->lootValue = 0;
    this->visibleToPlayer = false;
    this->cohesion = 0.00f;
    this->ralliedOnDay = 0;
    this->Control = ESquadControl::Full;
    this->rallyingStatus = ERallyingStatus::Disbanded;
    this->enemySpotted = false;
    this->isEngaged = false;
    this->engagementPercentage = 0.00f;
    this->concealmentLevel = 0;
    this->ownerPawnSetupIndex = 0;
    this->previousMoraleChangeTime = 0.00f;
}

