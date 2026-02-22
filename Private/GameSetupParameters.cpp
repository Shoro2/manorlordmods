#include "GameSetupParameters.h"

FGameSetupParameters::FGameSetupParameters() {
    this->goals = EGameGoals::Endless;
    this->numGenericAILords = 0;
    this->adversary_baron = false;
    this->AI_aggressiveness = 0;
    this->maxBanditCamps = 0;
    this->initialBanditCamps = 0;
    this->raidingFrequency = 0;
    this->yearsUntilFirstRaid = 0;
    this->generateWaterVeins = false;
    this->resourcesRandomization = 0;
    this->startingSuppliesMultiplier = 0;
    this->armamentDelivery = false;
    this->loyaltyLossRate = 0.00f;
    this->consumptionRate = 0.00f;
    this->treeGrowthRate = 0.00f;
    this->requirementDiscontentBias = 0;
    this->royalTaxMultiplier = 0;
    this->spoilage = 0;
    this->startingDay = 0;
    this->weatherDamage = 0;
}

