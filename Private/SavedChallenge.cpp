#include "SavedChallenge.h"

FSavedChallenge::FSavedChallenge() {
    this->ID = 0;
    this->challengedPawnIndex = 0;
    this->challengedByPawnIndex = 0;
    this->daysLeft = 0;
    this->contested = false;
    this->influenceStolen = 0;
    this->Status = EChallengeStatus::Winning;
    this->DaysInBattle = 0;
}

