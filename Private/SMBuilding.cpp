#include "SMBuilding.h"

ASMBuilding::ASMBuilding(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanBeInCluster = false;
    this->buildingMaster = NULL;
    this->controllableGate = NULL;
}


