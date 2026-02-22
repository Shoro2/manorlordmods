#include "MLWaterBodyRiver.h"

AMLWaterBodyRiver::AMLWaterBodyRiver(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bGenerateCollision = true;
    this->BankCollisionOffset = 0.00f;
    this->SubdivisionTargetLength = 1024.00f;
}


