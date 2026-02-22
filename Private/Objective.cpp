#include "Objective.h"

FObjective::FObjective() {
    this->objectiveType = EObjectiveType::None;
    this->TargetMinimum = 0;
    this->TargetMaximum = 0;
    this->trackIncrement = false;
    this->markDone = false;
    this->hidden = false;
}

