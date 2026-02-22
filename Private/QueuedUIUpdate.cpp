#include "QueuedUIUpdate.h"

FQueuedUIUpdate::FQueuedUIUpdate() {
    this->Region = NULL;
    this->UpdateType = EQueuedUIUpdateType::RegionalStock;
    this->goodType = 0;
}

