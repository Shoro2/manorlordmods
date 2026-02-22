#include "RTSMultiEngineCPP.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "SnapDebris.h"
#include "Templates/SubclassOf.h"

ARTSMultiEngineCPP::ARTSMultiEngineCPP(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->Delta = 0.00f;
    this->gameSpeed = 1.00f;
    this->spawnAIPlayers = false;
    this->declareWarInstant = false;
    this->AI_canBuild = false;
    this->SM_WindmillShaft = NULL;
    this->CullDistance = 23000.00f;
    this->cullDistanceFar = 16000.00f;
    this->cullDistanceMid = 8000.00f;
    this->cullDistanceClose = 4000.00f;
    this->cullDistanceBuildings = 53000.00f;
    this->DT_ConstructionBPs = NULL;
    this->DT_AnimsetCombat = NULL;
    this->DT_AnimsetWork = NULL;
    this->DT_AnimsetGoat = NULL;
    this->DT_AnimsetChicken = NULL;
    this->DT_AnimsetSheep = NULL;
    this->DT_AnimsetDeer = NULL;
    this->DT_AnimsetHorse = NULL;
    this->DT_AnimsetBird = NULL;
    this->DT_AnimsetOx = NULL;
    this->DT_AnimsetHound = NULL;
    this->DT_AnimsetPig = NULL;
    this->DT_AnimsetHare = NULL;
    this->DT_AnimsetCombined = NULL;
    this->RT_fields = NULL;
    this->RT_plowing = NULL;
    this->RT_Fertility = NULL;
    this->RT_ForestMask = NULL;
    this->RT_Desirability = NULL;
    this->Canvas = NULL;
    this->RT_RegionMask = NULL;
    this->RT_RegionBorderMask = NULL;
    this->RT_roads = NULL;
    this->RT_holes = NULL;
    this->RT_veins = NULL;
    this->marketPattern = NULL;
    this->softMask = NULL;
    this->pitMaskNew = NULL;
    this->DT_socketMeshes = NULL;
    this->mapMiddleHeight = 5000.00f;
    this->mapFadeDistance = 55000.00f;
    this->depositMaterial = NULL;
    this->depositMaterial_Salt = NULL;
    this->depositMaterial_Clay = NULL;
    this->foliageCustomDataBP = NULL;
    this->treeBP = NULL;
    this->iranyriveresourceBP = NULL;
    this->stoneResourceBP = NULL;
    this->beeResourceBP = NULL;
    this->shrubResourceBP = NULL;
    this->shroomResourceBP = NULL;
    this->handcartResourceBP = NULL;
    this->bigcartResourceBP = NULL;
    this->fishResourceBP = NULL;
    this->ladderResourceBP = NULL;
    this->ironResourceBP = NULL;
    this->clayResourceBP = NULL;
    this->saltResourceBP = NULL;
    this->WMaster = NULL;
    this->ThunderLightBP = NULL;
    this->SM_arrow = NULL;
    this->SM_torch = NULL;
    this->SnapDebris = CreateDefaultSubobject<USnapDebris>(TEXT("SnapDebris"));
    this->SoundBuddy = NULL;
    this->DT_resourceSounds = NULL;
    this->PS_dustPuff = NULL;
    this->PS_BLoodSplatter = NULL;
    this->PS_Thunder = NULL;
    this->PS_dragDust = NULL;
    this->PS_Impact_Smithing = NULL;
    this->PS_Impact_Leaves = NULL;
    this->PS_Impact_Wood = NULL;
    this->PS_Impact_WoodDry = NULL;
    this->PS_Impact_Stone = NULL;
    this->PS_Impact_Plow = NULL;
    this->PS_Impact_PloughHeavy = NULL;
    this->PS_Impact_Sow = NULL;
    this->PS_fireBig = NULL;
    this->PS_fireGrid = NULL;
    this->PS_fireplaceSmoke = NULL;
    this->PS_chimneySmoke = NULL;
    this->PS_malthouseSmoke = NULL;
    this->PS_Splash = NULL;
    this->PS_BucketSplash = NULL;
    this->PS_FlourPuff = NULL;
    this->PS_ThunderHit = NULL;
    this->PS_FieryHit = NULL;
    this->PS_Bees = NULL;
    this->PS_TorchImpact = NULL;
    this->PS_fallingLeaves = NULL;
    this->predictionCalculationDays = 365;
    this->locationUpdateCounter = 0.00f;
    this->fieldRTmat = NULL;
    this->M_marketDecalMat = NULL;
    this->workDecalMat = NULL;
    this->moduleMaskMaterial = NULL;
    this->M_overlay_moduleMasks = NULL;
    this->M_overlay_fertility = NULL;
    this->updatePosLag = 0;
    this->lastUniqueID = 0;
    this->basePrice = 0.00f;
    this->DT_units = NULL;
    this->fogOfWar = false;
    this->MapSize = 223200.00f;
    this->bannerAnimBP = NULL;
    this->bannerBP = NULL;
    this->kingsFavour_daysLeft = 0;
    this->ghostMaterial = NULL;
    this->DT_MercenaryCompanies = NULL;
    this->prepareRoadsForEditor = false;
    this->enableFertilityGrid = false;
    this->instancePositionUpdate = false;
    this->deltaDiff = 0.00f;
    this->traderTimer = 0;
    this->isConstructionAllowed = true;
    this->dustyMap = false;
    this->spawnMerchants = false;
    this->canRain = false;
    this->canSnow = false;
    this->bloodDecalBP = NULL;
    this->drawBattleDebug = false;
    this->drawImportantDebug = false;
    this->drawPathfindingDebug = false;
    this->drawDebg_roadGuidePoints = false;
    this->plagueDecalMat = NULL;
    this->unitJustSpawned = false;
    this->boundsDecalMatRoadsOK = NULL;
    this->sidewalkMesh = NULL;
    this->SM_fence = NULL;
    this->SM_fence_B = NULL;
    this->SM_plankFence = NULL;
    this->townwallMesh = NULL;
    this->SM_palisade = NULL;
    this->SM_stoneWall = NULL;
    this->SM_storage_log = NULL;
    this->SM_banner = NULL;
    this->DT_Upgrades = NULL;
    this->borderSegmentMesh = NULL;
    this->SM_FatRoad = NULL;
    this->SM_shrubbyMesh = NULL;
    this->lastVeloUpdTime = 0.00f;
    this->RVT_Landscape = NULL;
    this->RVT_RoadMask = NULL;
    this->RVT_Heightmap = NULL;
    this->RVT_ModuleMask = NULL;
    this->RVT_SnowDisplacementMask = NULL;
    this->fieldMaskMaterial = NULL;
    this->marketMaskMaterial = NULL;
    this->vegetableFieldMat = NULL;
    this->DT_BuildingPartAssemblies = NULL;
    this->DT_BuildingPartMeshes = NULL;
    this->DT_gameplayStaticMeshes = NULL;
    this->SM_wheat = NULL;
    this->SM_flax = NULL;
    this->SM_willowBranches = NULL;
    this->SM_herbs = NULL;
    this->SM_appleTree = NULL;
    this->SM_appleTree_old = NULL;
    this->empty_instance = NULL;
    this->SM_dirtPlane = NULL;
    this->questDirector = NULL;
    this->lastObstructionYaw = 0.00f;
    this->workAreaMesh = NULL;
    this->testAnimClip = NULL;
    this->testSzkeletalMesh = NULL;
    this->marketfieldMat = NULL;
    this->roadConnectionMat = NULL;
    this->wallMarker = NULL;
    this->gatehousePreviewMesh = NULL;
    this->randomFormationSocketMesh = NULL;
    this->writeDebugLogs = true;
    this->shouldUpdateDebugLog_generalAI = false;
    this->shouldUpdateDebugLog_tacticsAI = false;
    this->shouldUpdateDebugLog_construction = false;
    this->gameSpeedScheduled = 1.00f;
    this->gameSpeedBeforePause = 1.00f;
    this->isGameSpeedScheduled = false;
    this->locomotionTicksAdjusted = 0.00f;
    this->locomotionTicksAdjustedPrevious = 0.00f;
    this->useLegacyVATM = false;
    this->isNightAndAffectsGameplay = false;
    this->unitBannerMesh = NULL;
    this->bouncedLightMaterial = NULL;
}

void ARTSMultiEngineCPP::updateSquadEquipmentStats(const int32& squadID) {
}

void ARTSMultiEngineCPP::updateRegionsAndBorders(bool inEditor) {
}

void ARTSMultiEngineCPP::updateRegionNamesTxt_Implementation() {
}

void ARTSMultiEngineCPP::updateProjectileManager() {
}

void ARTSMultiEngineCPP::updatePlayerRequests() {
}

void ARTSMultiEngineCPP::updateOpenClaims() {
}

void ARTSMultiEngineCPP::updateKingsFavourite() {
}

void ARTSMultiEngineCPP::updateFreeMerchants() {
}

void ARTSMultiEngineCPP::updateChallengeStatus(FChallenge& Challenge) {
}

void ARTSMultiEngineCPP::updateChallengeDay() {
}

void ARTSMultiEngineCPP::updateAllPawnsCommandedSquadsAndEnemies() {
}

void ARTSMultiEngineCPP::updateAllPawnsArmies() {
}

void ARTSMultiEngineCPP::updateAllChallenges() {
}

void ARTSMultiEngineCPP::triggerExampleBattle() {
}

bool ARTSMultiEngineCPP::Triangulate_Process(const TArray<FVector>& contour, TArray<FVector>& Result) {
    return false;
}

bool ARTSMultiEngineCPP::Triangulate_InsideTriangle(float Ax, float Ay, float bX, float bY, float Cx, float Cy, float Px, float Py) {
    return false;
}

float ARTSMultiEngineCPP::Triangulate_Area(const TArray<FVector>& contour) {
    return 0.0f;
}

void ARTSMultiEngineCPP::triangulate(TArray<FVector>& Vertices, TArray<FTriangle>& outTriangles) {
}

void ARTSMultiEngineCPP::splitRoadWithBorder(ARoad* roadToSplit, const TArray<FVector>& fieldPoints) {
}

void ARTSMultiEngineCPP::spawnRaiders(const int32 numSquads, const FVector& armyCenter) {
}

APawnCPP* ARTSMultiEngineCPP::spawnNewAILord(const FString& lordsName, bool isFemale, UTexture2D* Portrait, bool canBuild) {
    return NULL;
}

void ARTSMultiEngineCPP::spawnMerchantHerd(ASMUnit* livestockMerchant) {
}

ASMUnit* ARTSMultiEngineCPP::spawnLivestockMerchant(ASMBuildingMaster* nearBuilding) {
    return NULL;
}

ASMUnit* ARTSMultiEngineCPP::SpawnLivestock(EUnitRole AnimalType, const FVector& animalSpawnPos, ARegion* Region) {
    return NULL;
}

ASMUnit* ARTSMultiEngineCPP::spawnFreeMerchant(ARegion* attachedToRegion) {
    return NULL;
}

void ARTSMultiEngineCPP::spawnEliteRaiders(const FVector& armyCenter) {
}

int32 ARTSMultiEngineCPP::spawnCompleteUnit(const FName& tempName, const FVector& Location, const FRotator& Rotation, APawnCPP* ownerPawn, int32 companyID, int32 arrivesInDays) {
    return 0;
}

void ARTSMultiEngineCPP::spawnBloodDecal(const FVector& Position) {
}

void ARTSMultiEngineCPP::spawnBanditCamp() {
}

void ARTSMultiEngineCPP::spawnAsyncContstrBPLazy() {
}

TArray<int32> ARTSMultiEngineCPP::spawnArmy(const FVector& Pos, const TArray<FName>& unitTypes, APawnCPP* ownerPawn, const int32& companyID, const int32& arrivesInDays) {
    return TArray<int32>();
}

void ARTSMultiEngineCPP::snapAngleToNearestRoadIfClose(const FVector& Pos, FRotator& outAngle) {
}

void ARTSMultiEngineCPP::simplifyPolygon(TArray<FVector>& Vertices) {
}

void ARTSMultiEngineCPP::setupUpgrades_Implementation() {
}

void ARTSMultiEngineCPP::setRegionsManor(ASMBuildingMaster* manor) {
}

void ARTSMultiEngineCPP::setDay(int32 day) {
}

bool ARTSMultiEngineCPP::segmentIntersectsSphere(const FVector& A, const FVector& B, const FVector& Origin, float Radius) {
    return false;
}

bool ARTSMultiEngineCPP::segmentCollidesWithAnyBuilding(const FSegment& Segment, const FBox2D& segmentBounds, bool countRoadPointArea) {
    return false;
}

void ARTSMultiEngineCPP::RespawnCameraBasedGroundCover() {
}

void ARTSMultiEngineCPP::resetCoreTimers() {
}

void ARTSMultiEngineCPP::rerollMercenaries() {
}

void ARTSMultiEngineCPP::removeDuplicateVectors(TArray<FVector>& vecArr, float minDistSq) {
}

void ARTSMultiEngineCPP::removeAllPPsCreatedBy(AActor* Actor) {
}

void ARTSMultiEngineCPP::removeAllObstaclesCreatedBy(AActor* Actor) {
}

void ARTSMultiEngineCPP::removeAllFieldSnapPointsCreatedBy(AActor* Actor) {
}

void ARTSMultiEngineCPP::refillMercenaries() {
}

void ARTSMultiEngineCPP::redrawForestMask() {
}

void ARTSMultiEngineCPP::redrawFertilitySlow() {
}

void ARTSMultiEngineCPP::redrawFertilityComplete() {
}

void ARTSMultiEngineCPP::RebuildWaterTextures() {
}

void ARTSMultiEngineCPP::randomizeRecruitmentPool() {
}

void ARTSMultiEngineCPP::projectCircularBorder(const FVector& Center, float Radius, TArray<FVector>& outSmoothBorder, TArray<FVector>& outBorder) {
}

TArray<FVector> ARTSMultiEngineCPP::projectBorder(FVector2D Dimensions, FTransform Transform) {
    return TArray<FVector>();
}

bool ARTSMultiEngineCPP::pointCollidesWithBuildingBorder(const FVector& Point) {
    return false;
}

void ARTSMultiEngineCPP::playResourceFx(int32 Type, bool putdown, const FVector& Pos) {
}

void ARTSMultiEngineCPP::playImpact(const int32& Type, const FVector& Location, const FRotator& EmitterRotation, const bool& particleEffect, const float& volumeMul) {
}

void ARTSMultiEngineCPP::playAmbientVoice() {
}

void ARTSMultiEngineCPP::placeSnowStep(const FVector& Pos) {
}

void ARTSMultiEngineCPP::pickNewLeader(int32 squadID) {
}

FVector ARTSMultiEngineCPP::pickNearestPos(const FVector& Pos, const TArray<FVector>& Options) {
    return FVector{};
}

float ARTSMultiEngineCPP::pairToFloat(const FVector2D& P) {
    return 0.0f;
}

float ARTSMultiEngineCPP::onTheSameSide(FVector P, FVector Q, FVector A, FVector B) {
    return 0.0f;
}

void ARTSMultiEngineCPP::OnParticleSystemFinished(UParticleSystemComponent* ps) {
}

bool ARTSMultiEngineCPP::isResourceFood(const int32& resourceType) {
    return false;
}

bool ARTSMultiEngineCPP::IsMinorTrade(int32 goodType) {
    return false;
}

bool ARTSMultiEngineCPP::isHarvestSeason() {
    return false;
}

bool ARTSMultiEngineCPP::isBuildingTypeValid(int32 buildingID) {
    return false;
}

uint8 ARTSMultiEngineCPP::isAreaObstructedByUnits(const FVector& Pos, const float radiusSq, ASMUnit* outUnit) {
    return 0;
}

bool ARTSMultiEngineCPP::intersectTwoComplexBorders(const TArray<FVector>& borderA, const TArray<FVector>& borderB, FVector& Out) {
    return false;
}

bool ARTSMultiEngineCPP::intersectRoads(const FVector& A, const FVector& B, const bool& Center, FVector& Out, bool simple, const FBox2D& segmentBounds) {
    return false;
}

bool ARTSMultiEngineCPP::intersectComplexBorders(const FBBorder& borderA, const TArray<FVector> borderB, FVector& Out) {
    return false;
}

bool ARTSMultiEngineCPP::intersectBorders(const FBBorder& borderA, const FBBorder& borderB, FVector& Out) {
    return false;
}

void ARTSMultiEngineCPP::initChallenge(APawnCPP* challengedPawn, APawnCPP* challengedBy, ARegion* Region) {
}

TArray<int32> ARTSMultiEngineCPP::hireMercs(FMercenaryCompany company, APawnCPP* pawnRef) {
    return TArray<int32>();
}

float ARTSMultiEngineCPP::getWindTimeAdjusted() {
    return 0.0f;
}

FVector4 ARTSMultiEngineCPP::getWeatherDetails() {
    return FVector4{};
}

FUpgrade ARTSMultiEngineCPP::getUpgradeData(int32 upgradeID) {
    return FUpgrade{};
}

FColor ARTSMultiEngineCPP::getUnusedPlayerColor() {
    return FColor{};
}

int32 ARTSMultiEngineCPP::getTradeValue(ARegion* Region, const FName& Filter, int32 startDay, int32 endDay) {
    return 0;
}

TArray<FTradeLogEntry> ARTSMultiEngineCPP::getTradeLogSummedTradedGoods(ARegion* Region, int32 startDay, int32 endDay) {
    return TArray<FTradeLogEntry>();
}

TArray<FTradeLogEntry> ARTSMultiEngineCPP::getTradeLogAllTradedGoods(ARegion* Region, int32 startDay, int32 endDay) {
    return TArray<FTradeLogEntry>();
}

float ARTSMultiEngineCPP::getSegmentToBorderParallelFactor(const FSegment& Segment, const TArray<FVector>& SmoothBorder, bool accountForDistance) {
    return 0.0f;
}

TSubclassOf<AResource> ARTSMultiEngineCPP::getResourceBP(const FName& resType) {
    return NULL;
}

bool ARTSMultiEngineCPP::getRelationTags(const APawnCPP*& pawnA, const APawnCPP*& pawnB, TArray<FName>& relationTags) {
    return false;
}

uint8 ARTSMultiEngineCPP::getRegionIndex(ARegion* Region) {
    return 0;
}

ARegion* ARTSMultiEngineCPP::getRegionFromIndex(uint8 regionIndex) {
    return NULL;
}

ARegion* ARTSMultiEngineCPP::getRegionByPos(const FVector& Pos, bool skipBoundCheck) const {
    return NULL;
}

void ARTSMultiEngineCPP::getRandomSquad_Implementation(FSquad& newSquad) {
}

int32 ARTSMultiEngineCPP::getRandomPeasantClothes() {
    return 0;
}

float ARTSMultiEngineCPP::getRandomObstructionYaw() {
    return 0.0f;
}

float ARTSMultiEngineCPP::getRandomObstructionForce() {
    return 0.0f;
}

int32 ARTSMultiEngineCPP::getRandomHead(bool isWoman, bool combat) {
    return 0;
}

int32 ARTSMultiEngineCPP::getRandomHat(bool isWoman, bool isBurgher) {
    return 0;
}

int32 ARTSMultiEngineCPP::getPriceOfGood(ARegion* Region, int32 goodType) {
    return 0;
}

int32 ARTSMultiEngineCPP::getPreviousMonthStartDay() {
    return 0;
}

int32 ARTSMultiEngineCPP::getPreviousMonthEndDay() {
    return 0;
}

APawnCPP* ARTSMultiEngineCPP::getPawnBySetupIndex(int32 Index) {
    return NULL;
}

float ARTSMultiEngineCPP::getPathPrice(const FVector& A, const FVector& B) {
    return 0.0f;
}

FVector ARTSMultiEngineCPP::getNearestUnobstructedMapEdgePos(const FVector& nearPos, float boundExtents) {
    return FVector{};
}

FVector ARTSMultiEngineCPP::getNearestMapEdgePos(const FVector& nearPos, bool openOnly) {
    return FVector{};
}

FLorePoint ARTSMultiEngineCPP::getNearestLorePoint() {
    return FLorePoint{};
}

ASMBuildingMaster* ARTSMultiEngineCPP::getNearestBuildingTo(const FVector& Location, TArray<ASMBuildingMaster*> buildingsToCheck) {
    return NULL;
}

int32 ARTSMultiEngineCPP::getMonthsTotal() {
    return 0;
}

float ARTSMultiEngineCPP::getModuleRadiusForBuildingID(int32 buildingID) {
    return 0.0f;
}

int32 ARTSMultiEngineCPP::getLowestImportPrice(ARegion* Region, int32 goodType, bool ignoreTradeRouteRequirements) {
    return 0;
}

void ARTSMultiEngineCPP::getLoadedConstructionTemplate_Implementation(const TSoftClassPtr<AConstruction>& constructionAsset, TSubclassOf<AConstruction>& outConstructionTemplate) {
}

FItem ARTSMultiEngineCPP::getItem(const int32 ItemId) {
    return FItem{};
}

FPair ARTSMultiEngineCPP::getImportPriceRange(ARegion* Region, int32 goodType, bool& OutMayIncludeTariff, bool ignoreTradeRouteRequirements) {
    return FPair{};
}

TArray<int32> ARTSMultiEngineCPP::GetGoodTypesInSubcategory(EItemSubcategory Subcategory) {
    return TArray<int32>();
}

float ARTSMultiEngineCPP::getGlobalDemandPriceMultiplierForGood(int32 goodType) {
    return 0.0f;
}

float ARTSMultiEngineCPP::getGameTimeAdjusted() {
    return 0.0f;
}

FVector ARTSMultiEngineCPP::getFieldDominatingAngle(const TArray<FVector>& fieldBorderPoints) {
    return FVector{};
}

int32 ARTSMultiEngineCPP::getFertilityIDandPos(const FVector& Pos, int32& outX, int32& outY) {
    return 0;
}

int32 ARTSMultiEngineCPP::getFertilityID(const FVector& Pos) {
    return 0;
}

float ARTSMultiEngineCPP::getFertilityAtGridID(int32 GridId, ECropType cropType) {
    return 0.0f;
}

float ARTSMultiEngineCPP::getFertility(const FVector& Pos, ECropType cropType) {
    return 0.0f;
}

void ARTSMultiEngineCPP::getFarmingInfo(ASMBuildingMaster* building, bool& isPlowing, bool& allPlowed, bool& allHarvested) {
}

UStaticMesh* ARTSMultiEngineCPP::getFallenTreeMeshForTree_Implementation(const UStaticMesh* treeMesh, FString& stumpName) {
    return NULL;
}

float ARTSMultiEngineCPP::getDistanceSquaredBetweenSmoothSegments(const TArray<FVector>& smoothA, const TArray<FVector>& smoothB) {
    return 0.0f;
}

FEquipment ARTSMultiEngineCPP::getDefaultMilitiaEquipmentForUnitTemplate(const FName& TemplateName) {
    return FEquipment{};
}

float ARTSMultiEngineCPP::GetDefaultApprovalRateForFactor(const EApprovalFactorType Type) const {
    return 0.0f;
}

TArray<FVector> ARTSMultiEngineCPP::getDeerLairLocations() {
    return TArray<FVector>();
}

int32 ARTSMultiEngineCPP::getDaysTotal() {
    return 0;
}

int32 ARTSMultiEngineCPP::getDayOfTheYear() {
    return 0;
}

int32 ARTSMultiEngineCPP::getCurrentMonth() {
    return 0;
}

void ARTSMultiEngineCPP::getConstructionBP_Implementation(const int32& HISM, TSubclassOf<AConstruction>& ConstructionBP) {
}

FSoftObjectPath ARTSMultiEngineCPP::getBuildingPartMeshPath(int32 iType) {
    return FSoftObjectPath{};
}

float ARTSMultiEngineCPP::getBuildingInternalOffsetFromWall(int32 bType) {
    return 0.0f;
}

FStat ARTSMultiEngineCPP::getBuildingData(int32 buildingID) {
    return FStat{};
}

ASMBuildingMaster* ARTSMultiEngineCPP::getBuildingByID(int32& UniqueID) {
    return NULL;
}

float ARTSMultiEngineCPP::getBorderLength(const TArray<FVector>& fieldPoints) {
    return 0.0f;
}

FUnitStat ARTSMultiEngineCPP::getAverageUnitStat(const FName& Temp) {
    return FUnitStat{};
}

FUnitStat ARTSMultiEngineCPP::getAverageEquipmentStat(const TArray<int32>& equipmentItems) {
    return FUnitStat{};
}

int32 ARTSMultiEngineCPP::getAvailableExportPrice(ARegion* Region, int32 goodType, bool bIgnoreTradeRestrictions) {
    return 0;
}

UDataTable* ARTSMultiEngineCPP::getAnimsetDataTable(const FName SetName) {
    return NULL;
}

FName ARTSMultiEngineCPP::getAnimNameForAnimID(int32 animID, UDataTable* AnimSet, int32 variationID) {
    return NAME_None;
}

EUnitRole ARTSMultiEngineCPP::getAnimalRoleFromGoodType(int32 goodType) {
    return EUnitRole::Husband;
}

TArray<FTradeLogEntry> ARTSMultiEngineCPP::getAllTradeLogEntriesForRegion(ARegion* Region) {
    return TArray<FTradeLogEntry>();
}

void ARTSMultiEngineCPP::generateFertilityValues() {
}

void ARTSMultiEngineCPP::fulfillKingsFavour() {
}

bool ARTSMultiEngineCPP::fitModuleTransformAlongBorder(const TArray<FVector>& targetBorderPoints, const TArray<FVector>& boundaryAreaPoints, float initialDistanceOffset, float moduleWidthHalf, float moduleHeightHalf, FTransform& OutTransform, float collisionDistanceIncrementValue, int32 maxAttempts, TArray<FVector> extraCollisionBorder) {
    return false;
}

void ARTSMultiEngineCPP::finishSpawningSoloBuildingAsync(FBuildingSpawnParams Params) {
}

AUnitSpawner* ARTSMultiEngineCPP::findUnitSpawnerWithTag(const FName& Tag) {
    return NULL;
}

ASMUnit* ARTSMultiEngineCPP::findUnitByPos(const FVector& Pos) {
    return NULL;
}

AResource* ARTSMultiEngineCPP::findResourceByPos(const FVector& Pos) {
    return NULL;
}

ARegion* ARTSMultiEngineCPP::findRegionByName(const FString& Name) {
    return NULL;
}

ARegion* ARTSMultiEngineCPP::findRegionByID(const int32& regionID) {
    return NULL;
}

int32 ARTSMultiEngineCPP::findLinkIDByPos(const FVector& Pos) {
    return 0;
}

FVector ARTSMultiEngineCPP::findGoodSquadMoveTargetNear(const FVector& Location) {
    return FVector{};
}

void ARTSMultiEngineCPP::finalizeChallenge(FChallenge& Challenge, APawnCPP* victoriousPawn) {
}

int32 ARTSMultiEngineCPP::extractBTypeFromTag(const AActor* Actor) {
    return 0;
}

int32 ARTSMultiEngineCPP::extractBTypeFromComponentTag(const UStaticMeshComponent* Component) {
    return 0;
}

void ARTSMultiEngineCPP::eraseBuildingReferences(ASMBuildingMaster* building) {
}

void ARTSMultiEngineCPP::eraseArmy(FArmy Army) {
}

bool ARTSMultiEngineCPP::doTwoSmoothBordersIntersect(const TArray<FVector>& borderA, const TArray<FVector>& borderB) {
    return false;
}

bool ARTSMultiEngineCPP::doesTriangulatedBorderCollideWithOneOfTheRoads(const FBox2D& bounds2d, const TArray<FVector>& triangulatedBorder, const TArray<ARoad*> roadsToCheck) {
    return false;
}

bool ARTSMultiEngineCPP::doesTriangulatedBorderCollideWithAnyRoad(TArray<FVector>& Border, TArray<FVector>& triangulatedBorder, const FVector& Center) {
    return false;
}

bool ARTSMultiEngineCPP::doesSegmentOverlapComplexBorder(const FSegment& Segment, const TArray<FVector>& Border, const TArray<FVector>& triangulated) {
    return false;
}

bool ARTSMultiEngineCPP::doesSegmentIntersectRectangle(const FSegment2D& Segment, const FBox2D& rect) {
    return false;
}

void ARTSMultiEngineCPP::destroyUnit(ASMUnit* unit) {
}

void ARTSMultiEngineCPP::clampFertilityValuesForDirtyCells() {
}

bool ARTSMultiEngineCPP::checkPointWithinComplexBorder(const FVector& Point, const TArray<FVector>& Points, const FVector& Center) {
    return false;
}

void ARTSMultiEngineCPP::changeFertilityCellUnclamped(int32 CellID, int32 cropType, float change) {
}

void ARTSMultiEngineCPP::changeFertilityCell(int32 CellID, int32 cropType, float change) {
}

void ARTSMultiEngineCPP::changeFertility(const FVector& Pos, int32 cropType, float change) {
}

float ARTSMultiEngineCPP::calculateWindmillEfficiency(const FVector& Pos) {
    return 0.0f;
}

bool ARTSMultiEngineCPP::breedAnimal(ASMUnit* father) {
    return false;
}

bool ARTSMultiEngineCPP::anyCivInRange(const FVector& Pos, const float& rangeSq, bool& isBuilding) {
    return false;
}

void ARTSMultiEngineCPP::alignToGroundQuatFast(FQuat& worldRotation, const FVector& groundNormal) {
}

void ARTSMultiEngineCPP::alignRotationToGround(FRotator& worldRotation, const FVector& groundNormal) {
}

bool ARTSMultiEngineCPP::addRelationTag(APawnCPP* pawnA, APawnCPP* pawnB, FName newTag) {
    return false;
}

void ARTSMultiEngineCPP::addPawnRelations(APawnCPP* pawnA) {
}

void ARTSMultiEngineCPP::AddCliffCollision() {
}


