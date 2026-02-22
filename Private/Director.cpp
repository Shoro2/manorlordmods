#include "Director.h"

ADirector::ADirector(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DT_Quests = NULL;
    this->scenario_nextActionDay = 0;
}

bool ADirector::startQuestFromPreset(const FName& questTag, APawnCPP* questPawn, TArray<FReward> extraRewards, ARegion* questRegion, bool askFirst, int32 daysLeftOverride) {
    return false;
}


