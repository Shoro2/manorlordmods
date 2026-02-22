#include "PixelFedConfiguration.h"

FPixelFedConfiguration::FPixelFedConfiguration() {
    this->backendId = EPixelFedBackendId::Invalid;
    this->qualitySet = false;
    this->percentSet = false;
    this->overrideScreenPercentage = 0;
    this->frameGenSet = false;
    this->sharpnessSet = false;
    this->dynResSet = false;
}

