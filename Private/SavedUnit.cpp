#include "SavedUnit.h"

FSavedUnit::FSavedUnit() {
    this->ownerPawnSetupIndex = 0;
    this->squadID = 0;
    this->currentUnitRole = EUnitRole::Husband;
    this->assignedUnitRole = EUnitRole::Husband;
    this->dead = false;
    this->deadAndAnimationFinished = false;
    this->hp = 0.00f;
    this->hunger = 0.00f;
    this->disease = 0.00f;
    this->cold = 0.00f;
    this->stamina = 0.00f;
    this->isHungry = false;
    this->isCold = false;
    this->monthlyConsumptionDay = 0;
    this->yearlyConsumptionDay = 0;
    this->Action = 0;
    this->idleTime = 0;
    this->craftingAnim = 0;
    this->repetitions = 0;
    this->targetRepetitions = 0;
    this->currentAnimSpd = 0.00f;
    this->currentAnimSpdDefault = 0.00f;
    this->animMode = EAnimMode::Work;
    this->job = 0;
    this->unitCollision = false;
    this->hasBasicNeeds = false;
    this->Age = 0;
    this->pregnancy = 0.00f;
    this->HoundOwnerIndex = 0;
    this->meleeTraining = 0.00f;
    this->archeryTraining = 0.00f;
    this->shieldSymbolIndex = 0.00f;
    this->assignedSquadID = 0;
    this->assignedEquippedSquadID = 0;
    this->isBeingRallied = false;
    this->workerFamilyID = 0;
    this->ProductionTrackerTimeTaskStarted = 0.00f;
    this->ProductionTrackerWaitingStartTime = 0.00f;
}

