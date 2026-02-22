#include "AmbientSoundNode.h"

AAmbientSoundNode::AAmbientSoundNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->masterPtr = NULL;
    this->nearbyHouses = 0;
}

void AAmbientSoundNode::updateBiome_Implementation() {
}


