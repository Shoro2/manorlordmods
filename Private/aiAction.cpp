#include "aiAction.h"

FaiAction::FaiAction() {
    this->Type = 0;
    this->flavour = 0;
    this->votes = 0;
    this->targetBuilding = NULL;
    this->targetUnit = NULL;
    this->Region = NULL;
    this->partner = NULL;
    this->resourceType = 0;
    this->resourceAmt = 0;
}

