#include "SavedRegion.h"

FSavedRegion::FSavedRegion() {
    this->isSettled = false;
    this->daySettled = 0;
    this->settlementType = ESettlementType::None;
    this->Approval = 0;
    this->publicOrder = 0;
    this->regionalWealth = 0;
    this->settlementLv = 0;
    this->devPoints = 0;
    this->reservedLogs = 0;
    this->retinueSquadID = 0;
    this->nextLivestockOrderIn = 0;
}

