#include "SMBanner.h"

ASMBanner::ASMBanner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MI_bannerMaterial = NULL;
}

void ASMBanner::setFrames(FVector newFrameData) {
}

FVector ASMBanner::getFrames() {
    return FVector{};
}

void ASMBanner::createDynamicMaterial(const float& colorA, const float& colorB, const float& heraldry) {
}


