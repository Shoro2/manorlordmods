#include "ResourceNode.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DecalComponent -FallbackName=DecalComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent

AResourceNode::AResourceNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->ResourceZoneDecal = CreateDefaultSubobject<UDecalComponent>(TEXT("ResourceZoneDecal"));
    this->resourceZoneMaterial = NULL;
    this->PaperMapDecal = CreateDefaultSubobject<UDecalComponent>(TEXT("PaperMapDecal"));
    this->PaperMapMaterial = NULL;
    this->PlayerController = NULL;
    this->playerPawn = NULL;
    this->masterPtr = NULL;
    this->GameInstance = NULL;
    this->PaperMapDecal->SetupAttachment(RootComponent);
    this->ResourceZoneDecal->SetupAttachment(RootComponent);
}

void AResourceNode::onPaperMapViewChanged(const bool bIsPaperMap) {
}


