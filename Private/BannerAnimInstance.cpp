#include "BannerAnimInstance.h"

UBannerAnimInstance::UBannerAnimInstance() {
    this->frameA = 0.00f;
    this->frameB = 0.00f;
    this->Blend = 0.00f;
    this->currentClip = NULL;
    this->playsClip = false;
    this->clipTotalFrames = 0.00f;
    this->clipFrame = 0.00f;
}


