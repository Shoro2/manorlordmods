#include "PixelFedState.h"

FPixelFedState::FPixelFedState() {
    this->frameGenMultiplier = 0;
    this->showFps = false;
    this->lastFrameFps = 0.00f;
    this->platformPreferedBackendId = EPixelFedBackendId::Invalid;
    this->activeBackendId = EPixelFedBackendId::Invalid;
    this->playerPreferedBackendId = EPixelFedBackendId::Invalid;
}

