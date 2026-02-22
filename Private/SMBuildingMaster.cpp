#include "SMBuildingMaster.h"
#include "ExpertiseComponent.h"
#include "MaintenanceComponent.h"
#include "ProductionTrackerComponent.h"
#include "ProficiencyComponent.h"

ASMBuildingMaster::ASMBuildingMaster(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    this->bCanBeInCluster = false;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->Region = NULL;
    this->ownerPawn = NULL;
    this->masterPtr = NULL;
    this->MaintenanceComponent = CreateDefaultSubobject<UMaintenanceComponent>(TEXT("MaintenanceComponent"));
    this->ProficiencyComponent = CreateDefaultSubobject<UProficiencyComponent>(TEXT("ProficiencyComponent"));
    this->ExpertiseComponent = CreateDefaultSubobject<UExpertiseComponent>(TEXT("ExpertiseComponent"));
    this->ProductionTrackerComponent = CreateDefaultSubobject<UProductionTrackerComponent>(TEXT("ProductionTrackerComponent"));
    this->typeBeforeChange = 0;
    this->fireAmt = 0.00f;
    this->onFire = false;
    this->ps_fire = NULL;
    this->PS_fireGrid = NULL;
    this->isBeingUpgraded = false;
    this->buildingFunction = EBuildingFunction::Default;
    this->bTabPinned = false;
    this->fieldWorkersNeeded = 0;
    this->fieldOperationMode = 0;
    this->plannedHarvest_DaysLeft = 0;
    this->plannedHarvest_PredictedYield = 0;
    this->yield = 0;
    this->forceHarvest = false;
    this->bRotateCrops = false;
    this->cropType2 = ECropType::None;
    this->cropType3 = ECropType::None;
    this->BoundsDecal = NULL;
    this->fieldDecal = NULL;
    this->borderIsClockwise = false;
    this->sleep = false;
    this->buildPriority = 4;
    this->workAreaLimited = false;
    this->workAreaRange = 0.00f;
    this->workAreaRangeSq = 0.00f;
    this->numActiveWorkerFamilies = 0;
    this->activeOxen = 0;
    this->maxOxen = 0;
    this->bDrawPeopleConnections = false;
    this->bDrawMarketConnections = false;
    this->collidesWithRoads = false;
    this->plagueDecal = NULL;
    this->marketDaysLeft = 0;
    this->artisanJob = 0;
    this->secondaryPriority = 1;
    this->allowLabourers = false;
    this->connectionNeedsVerifying = false;
    this->field_sowingPerc = 0.00f;
    this->field_ploughingPerc = 0.00f;
    this->field_growingPerc = 0.00f;
    this->field_harvestingPerc = 0.00f;
    this->field_numReadyToHarvest = 0;
    this->field_numUnplowed = 0;
    this->field_numSown = 0;
    this->numStoredGeneric = 0;
    this->numStoredLarge = 0;
    this->numStoredPantry = 0;
    this->storageLimitGeneric = 0;
    this->storageLimitLarge = 0;
    this->storageLimitPantry = 0;
    this->vegetationEraseStage = 0;
    this->waterSupply = 0;
    this->bModuleMaster = false;
    this->moduleMasterPtr = NULL;
    this->areaMasterBld = NULL;
    this->sellingType = 0;
    this->targetSquadSize = 0;
    this->snappedToRoad = NULL;
    this->isConnectedToTradeNetwork = false;
    this->lv = 1;
    this->supplyOverstocking = 0;
    this->needsRefueling = false;
    this->refueled = false;
    this->refuelDay = -1;
    this->stockFuelFor = 0;
    this->productionFocus = 0;
    this->mourningPeriod = 0;
    this->VAMP_AnimatedBuildingBP = NULL;
    this->VAMP_isPlaying = false;
    this->unitCache_transportTasks_lastTimeCached = 0.00f;
    this->trainConnectionSource = NULL;
    this->trainConnectionTarget = NULL;
    this->trainConnectionRegion = NULL;
    this->muleTrain_buyingType = -1;
    this->muleTrain_sellingType = -1;
    this->allowMarketStalls = true;
}

void ASMBuildingMaster::verifyStorageProblems() {
}

bool ASMBuildingMaster::useUpgrade(int32 ID) {
    return false;
}

void ASMBuildingMaster::updateRoadDecalMaterials() {
}

void ASMBuildingMaster::updateResourceSurplusCache() {
}

void ASMBuildingMaster::updatePremadeFieldPoints_Implementation() {
}

void ASMBuildingMaster::updateParticleSystemBasedOnWorkforce() {
}

void ASMBuildingMaster::updateNearbyWindmillEfficiency() {
}

void ASMBuildingMaster::updateMuleShoppingList() {
}

void ASMBuildingMaster::UpdateFieldCache(bool ploughing, bool sowing, bool growing, bool harvesting) {
}

void ASMBuildingMaster::updateFenceVisibilityBasedOnNeighbours(bool applyVisibilityChange) {
}

bool ASMBuildingMaster::unassignSingleWorkerFamily() {
    return false;
}

void ASMBuildingMaster::triangulateExtensionArea(int32 slotID) {
}

void ASMBuildingMaster::takeOverOrAddMarketStalls() {
}

void ASMBuildingMaster::StartFire() {
}

AActor* ASMBuildingMaster::spawnVAMPAnimatedBuildingBP(FSoftClassPath BlueprintPath, const FTransform& WorldTransform) {
    return NULL;
}

void ASMBuildingMaster::spawnRandomClutter(const FSegment& facade) {
}

void ASMBuildingMaster::spawnPlotDressing(int32 dressingType, const TArray<FVector>& sideA, const TArray<FVector>& sideB, const TArray<FVector>& sideC) {
}

UStaticMeshComponent* ASMBuildingMaster::spawnModuleMask() {
    return NULL;
}

void ASMBuildingMaster::spawnManorServantsInside(int32 numServants) {
}

void ASMBuildingMaster::spawnFieldBorderShrubbery(const TArray<FVector>& borderPoints) {
}

void ASMBuildingMaster::spawnBuildingsForUpgrade(const EUpgradeType upgradeType) {
}

ASMUnit* ASMBuildingMaster::spawnAnimal(EUnitRole animalRole) {
    return NULL;
}

bool ASMBuildingMaster::shouldShowCraftingSpeed() {
    return false;
}

bool ASMBuildingMaster::shouldDisplayProductivityTracker() {
    return false;
}

void ASMBuildingMaster::setWorkArea(const FVector& Center, const float& Range) {
}

void ASMBuildingMaster::SetupBuilding() {
}

void ASMBuildingMaster::setTabIsOpen(bool IsOpen) {
}

void ASMBuildingMaster::setSleep(bool newSleep) {
}

void ASMBuildingMaster::SetProtectResourceArea(bool InSetting) {
}

void ASMBuildingMaster::SetPriority(int32 NewPriority) {
}

void ASMBuildingMaster::setCustomBuildingFlag(int32 flagID, uint8 Value) {
}

void ASMBuildingMaster::setCropType(ECropType NewType) {
}

void ASMBuildingMaster::setConstructionPaused(bool paused) {
}

void ASMBuildingMaster::resetWorkArea() {
}

bool ASMBuildingMaster::removeActiveWorkerFamily() {
    return false;
}

void ASMBuildingMaster::playVAMPAnimation(FName AnimationName) {
}

void ASMBuildingMaster::playChimneySmoke() {
}

bool ASMBuildingMaster::orderLivestock(int32 Type) {
    return false;
}

float ASMBuildingMaster::muleTrain_getValueRatio() {
    return 0.0f;
}

bool ASMBuildingMaster::isWinter() {
    return false;
}

bool ASMBuildingMaster::isTavern() {
    return false;
}

bool ASMBuildingMaster::isStorageTypeBuilding() {
    return false;
}

bool ASMBuildingMaster::IsRubble() const {
    return false;
}

bool ASMBuildingMaster::isResidentialBuilding() {
    return false;
}

bool ASMBuildingMaster::IsMineBuilding() const {
    return false;
}

bool ASMBuildingMaster::isMarketStall() {
    return false;
}

bool ASMBuildingMaster::isMarketAssignable() {
    return false;
}

bool ASMBuildingMaster::isManor() {
    return false;
}

bool ASMBuildingMaster::isHomelessTent() {
    return false;
}

bool ASMBuildingMaster::isFlammable() {
    return false;
}

bool ASMBuildingMaster::isFamilyBusyAtWorkplace(const FWorkerFamily& WorkerFamily) {
    return false;
}

bool ASMBuildingMaster::isDesiredMilitaryStockAtHomeReached() {
    return false;
}

void ASMBuildingMaster::hireExtraRetinue() {
}

bool ASMBuildingMaster::hasUpgrade(int32 upgradeID) const {
    return false;
}

bool ASMBuildingMaster::hasRoadSnapPoints(int32 bType) {
    return false;
}

bool ASMBuildingMaster::hasReachedTransportLimits(const FVector& requestLocation) {
    return false;
}

bool ASMBuildingMaster::hasOrder(const int32& orderType) {
    return false;
}

bool ASMBuildingMaster::hasModuleOfType(int32 moduleType) {
    return false;
}

bool ASMBuildingMaster::hasMaxActiveWorkerFamilies() {
    return false;
}

int32 ASMBuildingMaster::getYieldReadyToHarvest() {
    return 0;
}

int32 ASMBuildingMaster::getWaterStorageCapacity() {
    return 0;
}

UVARuntimeComponent* ASMBuildingMaster::GetVARuntime() {
    return NULL;
}

TArray<FGood> ASMBuildingMaster::GetUpgradeResourceCost(const int32 InUpgradeID) const {
    return TArray<FGood>();
}

int32 ASMBuildingMaster::GetType() {
    return 0;
}

int32 ASMBuildingMaster::GetTriggeringRequirementLevel(const FRequirementCollection& InRequirementCollection) const {
    return 0;
}

TArray<uint8> ASMBuildingMaster::getTrigerringRequirements() {
    return TArray<uint8>();
}

TArray<int32> ASMBuildingMaster::getTradeableGoods() {
    return TArray<int32>();
}

FString ASMBuildingMaster::getTownName() {
    return TEXT("");
}

int32 ASMBuildingMaster::GetTotalProductivityValueInPercents() const {
    return 0;
}

int32 ASMBuildingMaster::getSurplusOfGood(int32 goodType, bool accountBringing, bool accountGrabbing, bool allowNegative) {
    return 0;
}

TArray<FGood> ASMBuildingMaster::getSurplusMilitaryEquipment() {
    return TArray<FGood>();
}

TArray<EResidentialRequirement> ASMBuildingMaster::GetSupplyCategoriesTriggeringApprovalLoss() {
    return TArray<EResidentialRequirement>();
}

TArray<int32> ASMBuildingMaster::GetSuppliedGoodTypesForRequirement(const FRequirementCollection& InRequirementCollection) const {
    return TArray<int32>();
}

float ASMBuildingMaster::GetSummedYieldModifierValue() const {
    return 0.0f;
}

TArray<FGood> ASMBuildingMaster::getStoredMilitaryEquipment() {
    return TArray<FGood>();
}

int32 ASMBuildingMaster::getStockOfDistributedGood(int32 goodType) {
    return 0;
}

int32 ASMBuildingMaster::getStallOwnerFamilyID() const {
    return 0;
}

float ASMBuildingMaster::getSown(int32& outNumSown) {
    return 0.0f;
}

bool ASMBuildingMaster::getSleep() {
    return false;
}

int32 ASMBuildingMaster::GetSatisfiedRequirementLevel(const FRequirementCollection& InRequirementCollection) const {
    return 0;
}

int32 ASMBuildingMaster::GetRetinueHireTreasuryCost() const {
    return 0;
}

FRequirementsPerLevel ASMBuildingMaster::GetResidentialUpgradeRequirements() const {
    return FRequirementsPerLevel{};
}

FRequirementsPerLevel ASMBuildingMaster::GetResidentialTriggeringRequirementLevels() const {
    return FRequirementsPerLevel{};
}

TArray<FResidentialRequirement> ASMBuildingMaster::GetResidentialRequirementsForSupplyCategory(EResidentialRequirement InSupplyCategory, const EItemSubcategory InMustHaveSubcategory) const {
    return TArray<FResidentialRequirement>();
}

TArray<FGood> ASMBuildingMaster::getRequestedMilitaryEquipment() {
    return TArray<FGood>();
}

ARegion* ASMBuildingMaster::getRegionOnLocation() {
    return NULL;
}

int32 ASMBuildingMaster::GetRegionalWealthCostForUpgrade(const int32 InUpgradeID) const {
    return 0;
}

ARegion* ASMBuildingMaster::GetRegion() const {
    return NULL;
}

float ASMBuildingMaster::getReconstructedCastleArea(TArray<FVector>& reconstructedSmoothBorder, TArray<FVector>& reconstructedTriangulatedBorder) {
    return 0.0f;
}

float ASMBuildingMaster::getRandomFloatInRangePredictable(float min, float max) {
    return 0.0f;
}

bool ASMBuildingMaster::GetProtectResourceArea() const {
    return false;
}

TArray<int32> ASMBuildingMaster::getProducingGoods(bool includeHidden) const {
    return TArray<int32>();
}

TArray<int32> ASMBuildingMaster::getProblems() {
    return TArray<int32>();
}

int32 ASMBuildingMaster::GetPriority() {
    return 0;
}

int32 ASMBuildingMaster::getPriceOfGood(int32 goodType) {
    return 0;
}

APawnCPP* ASMBuildingMaster::getOwnerPawn() {
    return NULL;
}

float ASMBuildingMaster::getOrderProgress(const int32& orderType) {
    return 0.0f;
}

TArray<ASMUnit*> ASMBuildingMaster::getOccupants() {
    return TArray<ASMUnit*>();
}

TArray<FWorkerFamily> ASMBuildingMaster::getOccupantFamiliesUI() {
    return TArray<FWorkerFamily>();
}

int32 ASMBuildingMaster::getNumStoredLogs() {
    return 0;
}

int32 ASMBuildingMaster::getNumResidingFamilies() {
    return 0;
}

int32 ASMBuildingMaster::getNumReadyToHarvest() {
    return 0;
}

int32 ASMBuildingMaster::getNumOrders(const int32& orderType) {
    return 0;
}

int32 ASMBuildingMaster::getNumMarketStallsOfType(int32 stallType) {
    return 0;
}

int32 ASMBuildingMaster::getNumMarketStalls() {
    return 0;
}

int32 ASMBuildingMaster::getNumConnectedBuildingsOfFunction(EBuildingFunction Function) {
    return 0;
}

FVector2D ASMBuildingMaster::getNumBuilders() const {
    return FVector2D{};
}

int32 ASMBuildingMaster::getNumActiveWorkerFamilies() {
    return 0;
}

TArray<uint8> ASMBuildingMaster::getNextLevelRequirments() {
    return TArray<uint8>();
}

ASMBuilding* ASMBuildingMaster::getNearestResource(const int32& resType, const FVector& Pos) {
    return NULL;
}

TArray<int32> ASMBuildingMaster::getModuleTypes() {
    return TArray<int32>();
}

int32 ASMBuildingMaster::getModularGarrisonLimit() {
    return 0;
}

TArray<EResidentialRequirement> ASMBuildingMaster::GetMissingSupplyCategories() const {
    return TArray<EResidentialRequirement>();
}

int32 ASMBuildingMaster::getMaxWorkerFamilies() const {
    return 0;
}

int32 ASMBuildingMaster::getMaxSonsPerFamily() {
    return 0;
}

int32 ASMBuildingMaster::getMaxResidingFamilies() {
    return 0;
}

int32 ASMBuildingMaster::getMaxOxen() {
    return 0;
}

int32 ASMBuildingMaster::getMaxOccupantsOfRole(EUnitRole roleToSearch) {
    return 0;
}

int32 ASMBuildingMaster::getLowestImportPrice(int32 goodType, bool ignoreTradeRouteRequirements) {
    return 0;
}

EUnitRole ASMBuildingMaster::getLivestockWorkerRole() {
    return EUnitRole::Husband;
}

int32 ASMBuildingMaster::getJobType() {
    return 0;
}

FItem ASMBuildingMaster::getItem(const int32& ItemId) {
    return FItem{};
}

bool ASMBuildingMaster::getIsTabOpened() {
    return false;
}

TArray<FGood> ASMBuildingMaster::getInventory(bool includeModules) {
    return TArray<FGood>();
}

FPair ASMBuildingMaster::getImportPriceRange(int32 goodType, bool& OutMayIncludeTariff, bool bIgnoreTradeLevel) {
    return FPair{};
}

float ASMBuildingMaster::getHarvested() {
    return 0.0f;
}

TArray<int32> ASMBuildingMaster::getGoodTypesForConstructionReserves() {
    return TArray<int32>();
}

TArray<int32> ASMBuildingMaster::getGoodTypesConsumedForCurrentProduction(bool includeTransitionary, bool includeSpecialReserve) {
    return TArray<int32>();
}

TArray<uint8> ASMBuildingMaster::getFilledTrigerringRequirements() {
    return TArray<uint8>();
}

int32 ASMBuildingMaster::getFieldWorkers() {
    return 0;
}

int32 ASMBuildingMaster::getFieldReadyToSow() {
    return 0;
}

int32 ASMBuildingMaster::getExtensionHISM(const int32& ExtensionType) {
    return 0;
}

float ASMBuildingMaster::GetExtensionAreaCostMultiplier() const {
    return 0.0f;
}

FString ASMBuildingMaster::getDisplayNameKey() const {
    return TEXT("");
}

TArray<FGood> ASMBuildingMaster::getDesiredMilitaryEquipmentStockAtHome() {
    return TArray<FGood>();
}

FBuildingDataStruct ASMBuildingMaster::getData() {
    return FBuildingDataStruct{};
}

float ASMBuildingMaster::getDailyPlantGrowth() {
    return 0.0f;
}

uint8 ASMBuildingMaster::getCustomBuildingFlag(int32 flagID) {
    return 0;
}

TArray<EResidentialRequirement> ASMBuildingMaster::GetCurrentResidentialSupplyCategories() const {
    return TArray<EResidentialRequirement>();
}

TArray<int32> ASMBuildingMaster::GetCurrentlyProducedGoodTypes() const {
    return TArray<int32>();
}

int32 ASMBuildingMaster::getCurrentlyProducedGoodType() {
    return 0;
}

float ASMBuildingMaster::getCurrentFoodSpoilageRate(int32 goodType) {
    return 0.0f;
}

ECropType ASMBuildingMaster::getCropType() {
    return ECropType::None;
}

TArray<int32> ASMBuildingMaster::getCraftingConsumedGoodTypes(bool includeTransitionary, bool includeSpecialReserve) {
    return TArray<int32>();
}

TArray<ASMBuilding*> ASMBuildingMaster::getControllableGates() {
    return TArray<ASMBuilding*>();
}

FName ASMBuildingMaster::getConstructionStatus() {
    return NAME_None;
}

FVector2D ASMBuildingMaster::getConstructionResourceSituation() {
    return FVector2D{};
}

int32 ASMBuildingMaster::getConstructionQueueID() {
    return 0;
}

float ASMBuildingMaster::getConstructionProgress() {
    return 0.0f;
}

bool ASMBuildingMaster::getConstructionPaused() {
    return false;
}

TArray<ASMBuildingMaster*> ASMBuildingMaster::getConnectedSupplyBuildings() {
    return TArray<ASMBuildingMaster*>();
}

TMap<ECollapseModifier, float> ASMBuildingMaster::GetCollapseModifiers() const {
    return TMap<ECollapseModifier, float>();
}

int32 ASMBuildingMaster::GetCollapseChance() const {
    return 0;
}

TArray<FGood> ASMBuildingMaster::getCastleReconstructionCost(bool bOnlyBuildFirstBuilding) {
    return TArray<FGood>();
}

FName ASMBuildingMaster::getCastleLevelFromArea(float Area) {
    return NAME_None;
}

UTexture2D* ASMBuildingMaster::getBuildingFunctionIcon() const {
    return NULL;
}

float ASMBuildingMaster::getBuildingArea() {
    return 0.0f;
}

TArray<ASMUnit*> ASMBuildingMaster::getBoundRetinue() {
    return TArray<ASMUnit*>();
}

float ASMBuildingMaster::getAvgPloughProgress(int32& outNumUnplowed) {
    return 0.0f;
}

float ASMBuildingMaster::getAvgCropProgress() {
    return 0.0f;
}

float ASMBuildingMaster::getAverageCropFertility(ECropType cropID) {
    return 0.0f;
}

TArray<FGood> ASMBuildingMaster::getAverageConsumption() {
    return TArray<FGood>();
}

int32 ASMBuildingMaster::getAvailableExportPrice(int32 goodType, bool bIgnoreTradeRestrictions) {
    return 0;
}

TArray<ECropType> ASMBuildingMaster::GetAvailableCropTypes() {
    return TArray<ECropType>();
}

TArray<ASMUnit*> ASMBuildingMaster::getAttendingMerchants() {
    return TArray<ASMUnit*>();
}

TArray<FGood> ASMBuildingMaster::GetAssignedMilitaryEquipmentMinusAlreadyWearing() {
    return TArray<FGood>();
}

TArray<FGood> ASMBuildingMaster::getAssignedMilitaryEquipment() {
    return TArray<FGood>();
}

TArray<FWorkerFamily> ASMBuildingMaster::getAssignedFamiliesUI() {
    return TArray<FWorkerFamily>();
}

TArray<ASMUnit*> ASMBuildingMaster::getAnimalsCurrentlyOnPasture() {
    return TArray<ASMUnit*>();
}

TArray<ASMUnit*> ASMBuildingMaster::getAnimals() {
    return TArray<ASMUnit*>();
}

TArray<ASMUnit*> ASMBuildingMaster::getAllWorkers() {
    return TArray<ASMUnit*>();
}

TArray<int32> ASMBuildingMaster::getAllPossibleUpgrades(bool bIncludeExtensions) const {
    return TArray<int32>();
}

TSet<EAffinityType> ASMBuildingMaster::GetAffinities() const {
    return TSet<EAffinityType>();
}

TMap<EYieldModifier, int32> ASMBuildingMaster::GetActiveYieldModifiersWithValues() const {
    return TMap<EYieldModifier, int32>();
}

TMap<EProductivityModifier, int32> ASMBuildingMaster::GetActiveProductivityModifiersWithValues() const {
    return TMap<EProductivityModifier, int32>();
}

ARegion* ASMBuildingMaster::findRegionByName(const FString& regionName) {
    return NULL;
}

void ASMBuildingMaster::findRegionAndOwner(ARegion* SetRegion) {
}

void ASMBuildingMaster::eraseVegetationSlow() {
}

void ASMBuildingMaster::eraseVegetation(const TArray<FVector>& triangulatedBorderToCheck) {
}

void ASMBuildingMaster::eraseCrops(bool erasePlowing) {
}

void ASMBuildingMaster::drawPeopleArcs() {
}

void ASMBuildingMaster::drawMarketArcs() {
}

bool ASMBuildingMaster::doesWallSegmentOverlap(const FSegment2D& wallSegment) {
    return false;
}

bool ASMBuildingMaster::doesFlipFlopProduction() {
    return false;
}

bool ASMBuildingMaster::doesFenceOverlapAnyUnhiddenNeighbourFence(USplineMeshComponent* fenceMesh) {
    return false;
}

bool ASMBuildingMaster::doesDistributeRequirementGoods() {
    return false;
}

bool ASMBuildingMaster::doesCastleModuleNeedReconstruction(AActor* Actor, int32 newModuleBuildingId, EWallType wallType) {
    return false;
}

bool ASMBuildingMaster::doesBuildingConsumeResource(int32 Type, bool includingForConstruction, bool includeWeaponReservation, bool includeTrade) {
    return false;
}

bool ASMBuildingMaster::displayStorageUI() {
    return false;
}

void ASMBuildingMaster::demolish(bool refund) {
}

void ASMBuildingMaster::convertBlueprintsToBuildings(bool bOnlyBuildFirstBuilding) {
}

void ASMBuildingMaster::consumeGoodNoCheck(int32 goodType) {
}

void ASMBuildingMaster::collapseBuilding() {
}

void ASMBuildingMaster::changeTrainConnectionRegion(int32 uniqueRegionID) {
}

void ASMBuildingMaster::ChangeProductionFocus(int32 NewProductionFocus) {
}

void ASMBuildingMaster::changeMuleTrain_sellingType(int32 NewType) {
}

void ASMBuildingMaster::changeMuleTrain_buyingType(int32 NewType) {
}

void ASMBuildingMaster::ChangeExtension(int32 Slot, int32 NewType) {
}

void ASMBuildingMaster::changeArtisanType(int32 ExtensionType) {
}

void ASMBuildingMaster::changeActiveLivestockWorkers(int32 amt) {
}

bool ASMBuildingMaster::canUpgrade(int32 ID, TArray<FName>& resonsCant) {
    return false;
}

bool ASMBuildingMaster::canSetWorkArea() {
    return false;
}

bool ASMBuildingMaster::CanSelectCropType() {
    return false;
}

bool ASMBuildingMaster::canMakeAnything() {
    return false;
}

bool ASMBuildingMaster::canHireRetinue() {
    return false;
}

bool ASMBuildingMaster::canConstructCastle(TArray<EReason>& outReasons) {
    return false;
}

void ASMBuildingMaster::cancelOrder(const int32& orderType) {
}

bool ASMBuildingMaster::canBuildingTypeSetupMarketStalls() {
    return false;
}

bool ASMBuildingMaster::canBeDemolished() {
    return false;
}

bool ASMBuildingMaster::canAffordCastleReconstruction() {
    return false;
}

void ASMBuildingMaster::callMarket() {
}

bool ASMBuildingMaster::buildingIsExtension(ASMBuilding* building) {
    return false;
}

bool ASMBuildingMaster::areExtensionUpgradesAvailable() {
    return false;
}

bool ASMBuildingMaster::anythingReadyToHarvest() {
    return false;
}

bool ASMBuildingMaster::AllResidentialRequirementsSatisfied() const {
    return false;
}

bool ASMBuildingMaster::allDirtFlattened() {
    return false;
}

void ASMBuildingMaster::addToInventory(const FGood& Good) {
}

bool ASMBuildingMaster::addActiveWorkerFamily() {
    return false;
}

void ASMBuildingMaster::abandonAllMarketStalls() {
}


