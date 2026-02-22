#include "PixelFedBackend.h"

FPixelFedBackend::FPixelFedBackend() {
    this->backendId = EPixelFedBackendId::Invalid;
    this->Version = 0;
    this->versionMinor = 0;
    this->isInstalled = false;
    this->isAvailable = false;
}

