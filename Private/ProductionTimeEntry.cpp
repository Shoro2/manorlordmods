#include "ProductionTimeEntry.h"

FProductionTimeEntry::FProductionTimeEntry() {
    this->timeTaken = 0.00f;
    this->numberOfTasksComplete = 0;
    this->productionCategory = EProductionCategory::None;
}

