#include "SnapDebris.h"

USnapDebris::USnapDebris(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->debrisTable = NULL;
}

bool USnapDebris::ReplaceActor(FName debrisName, AActor* actorToReplace, bool destroyReplacedActor) {
    return false;
}

int32 USnapDebris::CleanupDebris(FVector Location, float MaxRange, FName FilterName) {
    return 0;
}

bool USnapDebris::AtTransform(FName debrisName, FTransform tr) {
    return false;
}

bool USnapDebris::AtLocationRotation(FName debrisName, FVector Location, FRotator Rotation) {
    return false;
}


