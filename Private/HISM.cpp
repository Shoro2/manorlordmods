#include "HISM.h"

FHISM::FHISM() {
    this->Mesh = NULL;
    this->isUnit = false;
    this->ID = 0;
    this->CustomDepth = 0;
    this->CullDistance = ECullDistanceCategory::Building;
}

