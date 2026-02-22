#include "FamilyConsumptionData.h"

FFamilyConsumptionData::FFamilyConsumptionData() {
    this->itemCategory = EItemCategory::None;
    this->ItemSubcategory = EItemSubcategory::None;
    this->ItemType = 0;
    this->Period = EPeriodType::None;
    this->daysLeft = 0;
    this->DaysInCurrentCycle = 0;
}

