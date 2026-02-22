#include "Task.h"

FTask::FTask() {
    this->Type = ETaskType::None;
    this->resourceType = 0;
    this->resourceAmt = 0;
    this->targetBuilding = NULL;
    this->finalBuilding = NULL;
    this->targetUnit = NULL;
    this->finalUnit = NULL;
    this->executed = false;
    this->Resource = NULL;
    this->ID = 0;
    this->bPaidInAdvance = false;
}

