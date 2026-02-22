#include "ClaimStatus.h"

FClaimStatus::FClaimStatus() {
    this->claimedBy = NULL;
    this->contestedBy = NULL;
    this->progress = 0.00f;
    this->bLocked = false;
}

