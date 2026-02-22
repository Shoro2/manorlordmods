#include "UnitDataStruct.h"

FUnitDataStruct::FUnitDataStruct() {
    this->squadID = 0;
    this->IsSelected = false;
    this->bodyType = 0;
    this->headType = 0;
    this->coifType = 0;
    this->wpnType = 0;
    this->helmetType = 0;
    this->shieldType = 0;
    this->bonusType = 0;
    this->bloody = 0.00f;
    this->row = 0;
    this->column = 0;
    this->unitCollision = false;
    this->hp = 0.00f;
}

