#include "LogEntry.h"

FLogEntry::FLogEntry() {
    this->Timestamp = 0.00f;
    this->opensMenu = 0;
    this->Actor = NULL;
    this->Region = NULL;
    this->Icon = 0;
    this->Problem = 0;
    this->fadesAfter = 0;
    this->dayOfTheYear = 0;
    this->IsDisplayed = false;
}

