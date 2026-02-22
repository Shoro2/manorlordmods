#include "ApprovalMemory.h"

FApprovalMemory::FApprovalMemory() {
    this->Type = EApprovalFactorType::hunger;
    this->day = 0;
    this->expirationDay = 0;
    this->Count = 0;
    this->past = false;
    this->effectByPopulation = 0.00f;
}

