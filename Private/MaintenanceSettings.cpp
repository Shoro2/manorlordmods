#include "MaintenanceSettings.h"

UMaintenanceSettings::UMaintenanceSettings() {
    this->MaintenancePendingDays = 30;
    this->MaintenanceEffectRatesInPercents[0] = 0;
    this->MaintenanceEffectRatesInPercents[1] = 0;
    this->MaintenanceEffectRatesInPercents[2] = 0;
    this->MaintenanceEffectRatesInPercents[3] = 0;
    this->MaintenanceEffectRatesInPercents[4] = 0;
    this->MaintenanceEffectRatesInPercents[5] = 0;
    this->MaintenanceEffectRatesInPercents[6] = 0;
    this->MaintenanceEffectRatesInPercents[7] = 0;
    this->MaintenanceEffectRatesInPercents[8] = 0;
}

int32 UMaintenanceSettings::GetMaintenanceEffectValue(EMaintenanceEffect InEffect) const {
    return 0;
}


