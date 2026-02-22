#include "ProceduralGroundCoverData.h"

FProceduralGroundCoverData::FProceduralGroundCoverData() {
    this->Category = EGroundCoverCategory::Generic;
    this->Density = 0.00f;
    this->bCastShadow = false;
    this->alignToGround = false;
}

