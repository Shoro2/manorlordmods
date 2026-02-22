#include "QueuedLinkerDataEdit.h"

FQueuedLinkerDataEdit::FQueuedLinkerDataEdit() {
    this->editType = EQueuedEditType::AddPP;
    this->Index = 0;
    this->mainThreadArrayOffset = 0;
}

