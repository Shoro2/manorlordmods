#include "SavedQuest.h"

FSavedQuest::FSavedQuest() {
    this->ID = 0;
    this->playedMessages = 0;
    this->daysLeft = 0;
    this->tier = 0;
    this->bTracking = false;
    this->bTimed = false;
    this->hidden = false;
    this->opportunity = false;
    this->canRefuse = false;
    this->Status = EQuestStatus::Active;
    this->issuedOnDay = 0;
    this->repeats = false;
    this->letterForm = false;
}

