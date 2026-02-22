#include "GhostStaticMeshActor.h"

AGhostStaticMeshActor::AGhostStaticMeshActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanBeInCluster = false;
    this->buildingType = -1;
    this->wallType = EWallType::None;
}


