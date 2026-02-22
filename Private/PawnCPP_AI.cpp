#include "PawnCPP_AI.h"

APawnCPP_AI::APawnCPP_AI(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->isAI = true;
    this->markerAnimationTimes.AddDefaulted(4);
    this->bDrawDebug = false;
    this->AI_general_cycles = 0;
    this->AI_tactics_cycles = 0;
}

void APawnCPP_AI::startAI(float Speed, bool canBuild) {
}

void APawnCPP_AI::RecalculateOptionsDebug() {
}

void APawnCPP_AI::PickBestOptionDebug() {
}


