#include "WeatherMaster.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ParticleSystemComponent -FallbackName=ParticleSystemComponent

AWeatherMaster::AWeatherMaster(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->masterPtr = NULL;
    this->dayLength = 40.00f;
    this->day = 0;
    this->daysTotal = 0;
    this->dayOfTheMonth = 0;
    this->Month = 0;
    this->monthsTotal = 0;
    this->Year = 1;
    this->season = 0;
    this->isHarvestSeason = false;
    this->wind = 0.00f;
    this->windTarget = 0.00f;
    this->snowLevel = 0.00f;
    this->snowTarget = 0.00f;
    this->snowing = 0.00f;
    this->targetSnowing = 0.00f;
    this->raining = 0.00f;
    this->targetRaining = 0.00f;
    this->targetCloudiness = 0.00f;
    this->wetness = 0.00f;
    this->cloudiness = 0.00f;
    this->rainfall = 0.00f;
    this->snowfall = 0.00f;
    this->isDrought = false;
    this->droughtLevel = 0.00f;
    this->fogLevel = 0.00f;
    this->rainMeter = 0;
    this->daysWithoutRainVariation = 0;
    this->isWinter = false;
    this->winterClose = false;
    this->Systems.AddDefaulted(2);
    this->psc_rain_heavy = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PSC_HeavyRain"));
    this->psc_snow_light = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PSC_LightSnow"));
    this->enableThunderstorm = false;
    this->sheepGrowth = 0;
    this->fertilityUpdateTimer = 0;
    this->damagingRain = true;
    this->grassCulled = false;
    this->daysSinceLastRaid = 0;
    this->daysUntilNextRaid = 0;
    this->lastBanditCampSpawnedDay = -1;
}

void AWeatherMaster::updateWind() {
}

void AWeatherMaster::updateMonthAndSeason() {
}

void AWeatherMaster::updateDay() {
}

void AWeatherMaster::spawnThunder() {
}

void AWeatherMaster::setWeatherSpeed(float newSpeed) {
}

void AWeatherMaster::setupSeasons(bool loadingASavedGame) {
}

void AWeatherMaster::setLandscapeGrassCulled(bool bCullGrass) {
}

double AWeatherMaster::getTotalDaysAndHours() {
    return 0.0;
}

int32 AWeatherMaster::getSeasonID(int32 dayNo) {
    return 0;
}

int32 AWeatherMaster::getMonthID() {
    return 0;
}

int32 AWeatherMaster::getMonthFromDay(int32 dayNo) {
    return 0;
}

FGameplayDate AWeatherMaster::getFutureDayAndMonth(const int32 InDaysAhead) {
    return FGameplayDate{};
}

int32 AWeatherMaster::getDayOfTheYear(int32 CurrentDay, int32 CurrentMonth) {
    return 0;
}

FGameplayDate AWeatherMaster::getDayAndMonthFromDaysTotal(int32 daysTotalToBreakDown) {
    return FGameplayDate{};
}

FGameplayDate AWeatherMaster::getCurrentDayAndMonth() {
    return FGameplayDate{};
}

int32 AWeatherMaster::calculateDayOfTheMonthForDay(int32 dayNo) {
    return 0;
}

int32 AWeatherMaster::calculateDayOfTheMonth() {
    return 0;
}


