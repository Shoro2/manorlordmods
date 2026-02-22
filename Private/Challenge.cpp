#include "Challenge.h"

FChallenge::FChallenge() {
    this->ID = 0;
    this->challengedPawn = NULL;
    this->challengedBy = NULL;
    this->daysLeft = 0;
    this->contested = false;
    this->influenceStolen = 0;
    this->Status = EChallengeStatus::Winning;
    this->Battlefield = NULL;
    this->DaysInBattle = 0;
}

