#include "Road.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SplineComponent -FallbackName=SplineComponent

ARoad::ARoad(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
    this->masterPtr = NULL;
    this->kingsRoad = false;
    this->isBlueprint = false;
    this->roadType = ERoadType::Regular;
    this->wallType = EWallType::None;
    this->platformLevel = EPlatformLevel::None;
    this->roadTangentScale = 1.00f;
    this->Spline = (USplineComponent*)RootComponent;
    this->roadWidth = 170.00f;
    this->spacing = 1200.00f;
    this->resampled = false;
    this->SplineSimplification_MinDistance = 10.00f;
    this->SplineSimplification_AngleThresholdDegrees = 5.00f;
    this->MaterialOverride = NULL;
    this->regionA = NULL;
    this->regionB = NULL;
    this->MI_Border = NULL;
    this->marketRoad = false;
    this->isBorder = false;
    this->bMapEdge = false;
    this->bOpenBorder = true;
}

void ARoad::updateForks(bool twoWayConnections) {
}

void ARoad::updateBorderMaterials(bool hoveringA, bool hoveringB, bool selectedA, bool selectedB) {
}

void ARoad::spawnRoadMeshes() {
}

UStaticMeshComponent* ARoad::spawnFoliageComponent(const FVector& Pos, UStaticMesh* StaticMesh) {
    return NULL;
}

void ARoad::snapSplineToMapEdge(float snapThresholdSq) {
}

void ARoad::SimplifySpline() {
}

void ARoad::setRVTMode(ERuntimeVirtualTextureMainPassType NewMode) {
}

void ARoad::setCommit(const bool& isCommiting) {
}

bool ARoad::intersectRoadCached(const FVector& Start, const FVector& End, FVector& Out, const bool& Center, const bool& simple) {
    return false;
}

bool ARoad::insertPointOnSegmentIfPlazaFound(const int32& SplinePoint, FVector& outPos) {
    return false;
}

TArray<FGood> ARoad::getConstructionCost() {
    return TArray<FGood>();
}

FVector ARoad::getCachedCenter() {
    return FVector{};
}

TArray<ASMBuildingMaster*> ARoad::getBuildingsNearRoadQuick(const float& distSq) {
    return TArray<ASMBuildingMaster*>();
}

void ARoad::fixBorderRegions() {
}

void ARoad::eraseVegetation() {
}

void ARoad::connectCachedToPathfinding() {
}

void ARoad::clearRoad() {
}

void ARoad::cleanSplineMeshes() {
}

void ARoad::adjustHeight(const bool inEditor) {
}

void ARoad::addRuntimeVirtualTexture(URuntimeVirtualTexture* newRVT, ERuntimeVirtualTextureMainPassType passType) {
}

void ARoad::addFieldSnapPoints() {
}


