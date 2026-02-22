#include "ProceduralFoliageSettings.h"

UProceduralFoliageSettings::UProceduralFoliageSettings() {
    this->proceduralGroundCoverTypes.AddDefaulted(27);
    this->numberOfCameraGroundCoverCellColumnsHalf = 14;
    this->cameraBasedGroundCoverCellSize = 1200.00f;
}


