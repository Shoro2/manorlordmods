#include "SavedRoad.h"

FSavedRoad::FSavedRoad() {
    this->roadTangentScale = 0.00f;
    this->roadType = ERoadType::Regular;
    this->wallType = EWallType::None;
    this->platformLevel = EPlatformLevel::None;
}

