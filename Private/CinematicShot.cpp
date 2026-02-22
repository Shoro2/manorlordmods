#include "CinematicShot.h"

FCinematicShot::FCinematicShot() {
    this->durationInSeconds = 0.00f;
    this->rotateAroundPivot = false;
    this->fadeInSeconds = 0.00f;
    this->fadeOutSeconds = 0.00f;
    this->boomArmLengthStart = 0.00f;
    this->boomArmLengthEnd = 0.00f;
    this->EaseOut = false;
    this->gameSpeed = 0.00f;
}

