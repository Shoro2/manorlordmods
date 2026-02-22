#include "Quest.h"

FQuest::FQuest() {
    this->ID = 0;
    this->playedMessages = 0;
    this->tier = 0;
    this->canRefuse = false;
    this->daysLeft = 0;
    this->bTracking = false;
    this->bTimed = false;
    this->repeats = false;
    this->hidden = false;
    this->opportunity = false;
    this->letterForm = false;
    this->adjustDaysLeftToIssuedDay = false;
    this->issuedOnDay = 0;
    this->Status = EQuestStatus::Active;
}

