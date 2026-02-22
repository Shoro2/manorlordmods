#include "PixelFedBackendChoices.h"

FPixelFedBackendChoices::FPixelFedBackendChoices() {
    this->desiredBackendId = EPixelFedBackendId::Invalid;
    this->hasQualityChoices = false;
    this->hasFrameGenChoices = false;
    this->hasSharpnessChoices = false;
    this->hasDynResChoices = false;
}

