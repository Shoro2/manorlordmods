#include "ProficiencySettings.h"

UProficiencySettings::UProficiencySettings() {
    this->MinExperiencePerCraft = 5;
    this->ExperienceCap = 500;
    this->ExpertiseDecayRate = 1.00f;
    this->MaxEffectiveProficiency = 0.30f;
    this->ProductivityBrackets.AddDefaulted(5);
    this->ArtisanBrackets.AddDefaulted(5);
    this->ProductivityCap = 200;
}


