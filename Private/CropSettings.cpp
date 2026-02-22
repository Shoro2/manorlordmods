#include "CropSettings.h"

UCropSettings::UCropSettings() {
    this->BaseDailyGrowthRate[0] = 0.00f;
    this->BaseDailyGrowthRate[1] = 0.00f;
    this->BaseDailyGrowthRate[2] = 0.00f;
    this->BaseDailyGrowthRate[3] = 0.00f;
    this->BaseDailyGrowthRate[4] = 0.00f;
    this->BaseDailyGrowthRate[5] = 0.00f;
    this->BaseDailyGrowthRate[6] = 0.00f;
    this->BaseDailyGrowthRate[7] = 0.00f;
    this->BaseDailyGrowthRate[8] = 0.00f;
    this->BaseDailyGrowthRate[9] = 0.00f;
    this->BaseDailyGrowthRate[10] = 0.00f;
    this->BaseDailyGrowthRate[11] = 0.00f;
    this->BaseDailyGrowthRate[12] = 0.00f;
    this->BaseDailyGrowthRate[13] = 0.00f;
    this->BaseDailyGrowthRate[14] = 0.00f;
    this->BaseYieldPer100Plants[0] = 400;
    this->BaseYieldPer100Plants[1] = 400;
    this->BaseYieldPer100Plants[2] = 400;
    this->BaseYieldPer100Plants[3] = 400;
    this->BaseYieldPer100Plants[4] = 400;
    this->BaseYieldPer100Plants[5] = 400;
    this->BaseYieldPer100Plants[6] = 400;
    this->BaseYieldPer100Plants[7] = 400;
    this->BaseYieldPer100Plants[8] = 400;
    this->BaseYieldPer100Plants[9] = 400;
    this->BaseYieldPer100Plants[10] = 400;
    this->BaseYieldPer100Plants[11] = 400;
    this->BaseYieldPer100Plants[12] = 400;
    this->BaseYieldPer100Plants[13] = 400;
    this->BaseYieldPer100Plants[14] = 400;
    this->HarvestGrowthThreshold = 0.30f;
}

bool UCropSettings::IsHarvestSeasonal(ECropType InCropType) {
    return false;
}


