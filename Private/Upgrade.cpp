#include "Upgrade.h"

FUpgrade::FUpgrade() {
    this->Icon = NULL;
    this->SoundEffect = NULL;
    this->bIsCostScalable = false;
    this->regionalWealth = 0;
    this->treasury = 0;
    this->minimumSettlementLevel = 0;
    this->minimumProsperity = 0;
    this->minimumHouseLv = 0;
    this->lockedInOutposts = false;
    this->bUseOnlyOnce = false;
    this->upgradesInto = 0;
}

