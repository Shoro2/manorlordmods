#include "HudCPP.h"

AHudCPP::AHudCPP(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DebugDisplay.AddDefaulted(1);
    this->warningCrop = NULL;
    this->warningBarn = NULL;
    this->recruitProgress = NULL;
    this->recruitAssembling = NULL;
    this->squadRibbon = NULL;
    this->squadBg = NULL;
    this->squadBgHighlight = NULL;
    this->squadDeer = NULL;
    this->squadLivestockMerchant = NULL;
    this->squadSwordsmen = NULL;
    this->squadSpearmen = NULL;
    this->squadBowmen = NULL;
    this->squadHorse = NULL;
    this->squadMilitia = NULL;
    this->squadMace = NULL;
    this->squadBraced = NULL;
    this->squadVisionObstructed = NULL;
    this->resBg = NULL;
    this->resIron = NULL;
    this->resTradepoint = NULL;
    this->resStone = NULL;
    this->resBee = NULL;
    this->resBandit = NULL;
    this->resSalt = NULL;
    this->resClay = NULL;
    this->resBerries = NULL;
    this->resShrooms = NULL;
    this->problem_pastureSpace = NULL;
    this->problem_occasionalNeed = NULL;
    this->problem_questionMark = NULL;
    this->problem_cantAfford = NULL;
    this->problem_canUpgrade = NULL;
    this->problem_homeless = NULL;
    this->problem_water = NULL;
    this->problem_extension = NULL;
    this->problem_spoil = NULL;
    this->problem_storage = NULL;
    this->defaultFont = NULL;
    this->bDrawBattleDebug = false;
    this->debug_numBattles = 0;
    this->debug_numFriendsInBattle = 0;
    this->debug_numStray = 0;
    this->debug_myMeleeStr = 0;
    this->debug_myMissileStr = 0;
    this->DT_HudIcons = NULL;
    this->bShouldClearDrawList = false;
}

void AHudCPP::onWorldDestroy(UWorld* World) {
}

bool AHudCPP::iconPositionTaken(const FVector2D& Pos) {
    return false;
}

UTexture2D* AHudCPP::getHudIconByName(FName IconName) {
    return NULL;
}

void AHudCPP::drawUIText(const FString& String, const FVector2D& Pos, const bool& drawBorder, const FColor& Color) {
}

void AHudCPP::drawIconTexture(const FIcon& iconToDraw) {
}

void AHudCPP::drawIcon(int32 ID, const FVector2D& Pos, float scale, float progress, const FColor& Tint) {
}

void AHudCPP::DrawHUD() {
}

void AHudCPP::drawBattleDebug() {
}

void AHudCPP::drawArc(const FVector& Start, const FVector& End, const FColor& Color, const float& Thickness) {
}

void AHudCPP::clearDrawList() {
}


