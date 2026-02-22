#include "Construction.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=PoseableMeshComponent -FallbackName=PoseableMeshComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent

AConstruction::AConstruction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Default Root Component"));
    this->burnedMaterial = NULL;
    this->burningMaterial = NULL;
    this->BuildingsMPC = NULL;
    this->defaultRootComponent = (USceneComponent*)RootComponent;
    this->stoneStructure = CreateDefaultSubobject<UPoseableMeshComponent>(TEXT("stoneStructure"));
    this->constructionProgress = 0.00f;
    this->reverseConstruction = false;
    this->isCollapsing = false;
    this->onFire = false;
    this->lastElementUpdatedID = 0;
    this->lastBoardUpdated = 0;
    this->isStoneConstruction = false;
    this->hasStoneFoundations = false;
    this->sortSideways = false;
    this->stoneStructure->SetupAttachment(RootComponent);
}

void AConstruction::updateElementVisibilityCommon() {
}

void AConstruction::updateConstructionLevel_Implementation() {
}

void AConstruction::updateBoardVisibilityFast() {
}

void AConstruction::sortElementsFast(TArray<UStaticMeshComponent*>& toSort, TArray<UStaticMeshComponent*>& sorted, TArray<FTransform>& sortedTransforms, TArray<FTransform>& sortedGroundTransforms) {
}

TArray<FName> AConstruction::sortBoneNamesByLocation(TArray<FName> sourceArr) {
    return TArray<FName>();
}

void AConstruction::setupConstructionFast() {
}

void AConstruction::setupConstruction_Implementation() {
}

void AConstruction::setOnFire_Implementation() {
}

void AConstruction::setData(const FVector& newData) {
}

FVector AConstruction::getData() {
    return FVector{};
}

void AConstruction::destroyConstructionBP() {
}


