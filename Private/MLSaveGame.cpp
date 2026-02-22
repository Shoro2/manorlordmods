#include "MLSaveGame.h"

UMLSaveGame::UMLSaveGame() {
    this->saveSlot = TEXT("saveGame_0");
    this->UserIndex = 0;
    this->day = 0;
    this->Year = 0;
    this->daysTotal = 0;
    this->monthsTotal = 0;
    this->rainMeter = 0;
    this->raining = 0.00f;
    this->rainingTarget = 0.00f;
    this->snowing = 0.00f;
    this->snowingTarget = 0.00f;
    this->wetness = 0.00f;
    this->cloudiness = 0.00f;
    this->targetCloudiness = 0.00f;
    this->snowLevel = 0.00f;
    this->isDrought = false;
    this->droughtLevel = 0.00f;
    this->gameTimeAdjusted = 0.00f;
    this->gameTicksAdjusted = 0;
    this->daysUntilNextRaid = 365;
    this->daysSinceLastRaid = 0;
    this->saveVersion = 0;
    this->AI_behaviour = 0;
    this->triggerQuests = false;
    this->enableFertilityGrid = false;
    this->currentGameVictoryStatus = EVictoryStatus::Ongoing;
    this->kingsFavour_daysLeft = 0;
    this->lastBanditCampSpawnedDay = 0;
    this->scenario_nextActionDay = 0;
}


