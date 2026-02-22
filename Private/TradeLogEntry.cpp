#include "TradeLogEntry.h"

FTradeLogEntry::FTradeLogEntry() {
    this->fromBuilding = NULL;
    this->toBuilding = NULL;
    this->fromRegionIndex = 0;
    this->toRegionIndex = 0;
    this->goodType = 0;
    this->goodAmt = 0;
    this->priceTotal = 0;
    this->daysTotal = 0;
    this->isImport = false;
}

