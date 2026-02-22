#include "BirdFlock.h"

ABirdFlock::ABirdFlock(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsEnabled = true;
    this->NumberOfBirds = 12;
    this->FlyingHeight = 4500.00f;
    this->FlockWidthHalf = 1200.00f;
    this->FlockHeightHalf = 150.00f;
    this->FlockTargetRandomRadius = 50000.00f;
    this->SteeringSpeed = 0.03f;
    this->FlockSpeed = 800.00f;
    this->QueueLandscapeRequests = 0.50f;
    this->QueueObstacleInfrontRequests = 0.50f;
    this->BirdsToSpawn = NULL;
}

FVector ABirdFlock::GetFlockLocation() {
    return FVector{};
}


