#include "PMaster.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=InstancedStaticMeshComponent -FallbackName=InstancedStaticMeshComponent

APMaster::APMaster(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->masterPtr = NULL;
    this->InstanceArrow = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("ISM_Arrow"));
    this->InstanceTorch = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("ISM_Torch"));
}

void APMaster::updateProj() {
}

void APMaster::shootProjectile(int32 Type, FVector Start, FVector End, float Height, ASMUnit* shooter) {
}


