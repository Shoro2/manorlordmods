#include "Squad.h"

FSquad::FSquad() {
    this->squadType = ESquadType::None;
    this->Icon = 0;
    this->iconTexture = NULL;
    this->card = NULL;
    this->MaxSize = 0;
    this->ID = 0;
    this->targetSquad = 0;
    this->arrivesIn = 0;
    this->payDay = 0;
    this->companyID = 0;
    this->spread = 0.00f;
    this->currentRegion = NULL;
    this->targetRegion = NULL;
    this->originRegion = NULL;
    this->avgPotential = 0.00f;
    this->visibleToPlayer = false;
    this->cohesion = 0.00f;
    this->rallied = false;
    this->ralliedOnDay = 0;
    this->Control = ESquadControl::Full;
    this->rallyingStatus = ERallyingStatus::Disbanded;
    this->enemySpotted = false;
    this->isEngaged = false;
    this->engagementPercentage = 0.00f;
    this->camp = NULL;
    this->lastSquadAIUpdateTime = 0;
    this->ownerPawn = NULL;
    this->ownerPawnSetupIndex = 0;
    this->concealmentLevel = 0;
    this->previousHornTime = 0.00f;
    this->previousMoraleChangeTime = 0.00f;
}

