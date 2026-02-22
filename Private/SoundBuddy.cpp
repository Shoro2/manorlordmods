#include "SoundBuddy.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AudioComponent -FallbackName=AudioComponent

ASoundBuddy::ASoundBuddy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->masterPtr = NULL;
    this->ambience_wind_close = CreateDefaultSubobject<UAudioComponent>(TEXT("ambience_treeWind_close"));
    this->ambience_wind_far = CreateDefaultSubobject<UAudioComponent>(TEXT("ambience_grassWind_far"));
    this->ambience_rain_close = CreateDefaultSubobject<UAudioComponent>(TEXT("ambience_rain_close"));
    this->cue_ambience_bigFire = NULL;
    this->cue_steps_grass_varB = NULL;
    this->cue_steps_grass_varC = NULL;
    this->cue_rustle_weapon = NULL;
    this->cue_rustle_shield = NULL;
    this->cue_rustle_pole = NULL;
    this->cue_rustle_cloth = NULL;
    this->cue_rustle_clank = NULL;
    this->cue_rustle_mail = NULL;
    this->cue_rustle_bow = NULL;
    this->cue_breathing = NULL;
    this->cue_male_idle = NULL;
    this->cue_torchHit = NULL;
    this->cue_deathImpact = NULL;
    this->cue_chargeImpact = NULL;
    this->cue_voice_far_combat = NULL;
    this->cue_voice_far_move = NULL;
    this->cue_voice_far_idle = NULL;
    this->cue_voice_far_charge = NULL;
    this->cue_voice_far_bandit = NULL;
    this->cue_voice_far_hold = NULL;
    this->cue_voice_far_draw = NULL;
    this->cue_voice_far_loose = NULL;
    this->cue_voice_far_retreat = NULL;
    this->cue_voice_far_morale_low = NULL;
    this->cue_voice_far_morale_high = NULL;
    this->cue_voice_far_broken = NULL;
    this->cue_voice_far_push = NULL;
    this->cue_voice_far_attack = NULL;
    this->cue_voice_bandit_idle = NULL;
    this->cue_voice_bandit_move = NULL;
    this->cue_voice_bandit_combat = NULL;
    this->cue_voice_bandit_charge = NULL;
    this->cue_voice_bandit_far_idle = NULL;
    this->cue_voice_bandit_far_move = NULL;
    this->cue_voice_bandit_far_combat = NULL;
    this->cue_voice_bandit_far_charge = NULL;
    this->cue_militiaRallyHorns = NULL;
    this->cue_militiaRallyConfirm = NULL;
    this->cue_zoomOnPeasant = NULL;
    this->cue_zoomOnPeasantLT = NULL;
    this->cue_placeWall = NULL;
    this->cue_firewoodCollapse = NULL;
    this->cue_hammerDown = NULL;
    this->Cue_ProcessLog = NULL;
    this->cue_smashIron = NULL;
    this->DT_AudioCues = NULL;
    this->lastSeldomSound = 0.00f;
}

void ASoundBuddy::updateObjectProximities() {
}

void ASoundBuddy::playSfxSeldom(bool is3d, const TArray<USoundBase*>& sounds, const FVector& Pos, float Volume, bool ultraRare, bool isVoice) {
}

void ASoundBuddy::playSfx(bool is3d, const TArray<USoundBase*>& sounds, const FVector& Pos, float Volume, bool canOverlap, bool isVoice, bool isUI) {
}

void ASoundBuddy::playQuickCueFromDB(const FName& cueName, const FVector& Pos, float Volume, float Speed) {
}

void ASoundBuddy::playQuickCue2DFromDB(const FName& cueName, float Volume, float Speed) {
}

void ASoundBuddy::playQuickCue2D(USoundBase* SoundCue, float Volume, float Speed) {
}

void ASoundBuddy::playQuickCue(USoundBase* SoundCue, const FVector& Pos, float Volume, float Speed) {
}

void ASoundBuddy::playIncidentalAmbientSounds(float DeltaTime) {
}

void ASoundBuddy::playGloops() {
}

void ASoundBuddy::pickAndPlay(TArray<USoundBase*> sounds, float Volume, const FVector& Pos) {
}

float ASoundBuddy::getPlayerCameraClearance() {
    return 0.0f;
}

void ASoundBuddy::filterPastSounds() {
}


