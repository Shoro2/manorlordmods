#include "SMUnit.h"

ASMUnit::ASMUnit(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Radius = 0.00f;
    this->dead = false;
    this->masterPtr = NULL;
    this->animalAssignedTo = NULL;
    this->Home = NULL;
    this->workerFamilyID = -1;
    this->potential = 0.00f;
    this->behaviourStance = EBehaviourStance::Neutral;
    this->pushStance = EPushStance::Balanced;
    this->pushStanceBeforeMoraleDrop = EPushStance::GiveGround;
    this->checkpoint = 0;
    this->LPathSpeedfactorCache = 0.00f;
    this->onRoad = NULL;
    this->locomotionAnim = 0;
    this->locomotionIsIdle = false;
    this->currAnim = -1;
    this->targetAnim = 0;
    this->Speed = 18.50f;
    this->realSpeed = 0.00f;
    this->closeToFinal = true;
    this->speedFactor = 1.00f;
    this->climbingSpeedFactor = 1.00f;
    this->squadLowestClimbingSpeedFactor = 0.00f;
    this->floor = 0;
    this->snappedToTarget = false;
    this->leftoverSpeed = 0.00f;
    this->velo = 0.00f;
    this->isOnBuilding = false;
    this->pathCheckTimer = 0.00f;
    this->obstructed = 0;
    this->avoidedObstruction = false;
    this->PathPoint = 0;
    this->spatialGridIndex = -1;
    this->Action = 0;
    this->wasIdle = 0;
    this->waitingOnTransportLimitsCounter = 0;
    this->performedHit = false;
    this->baseAttack = 0.00f;
    this->baseDefence = 0.00f;
    this->baseRange = 0.00f;
    this->baseBlock = 0.00f;
    this->baseCharge = 0.00f;
    this->att = 0.00f;
    this->rangedAtt = 0.00f;
    this->Def = 0.00f;
    this->Range = 0.00f;
    this->rangeSq = 0.00f;
    this->shootingRange = 0.00f;
    this->shootingRangeSq = 0.00f;
    this->bLock = 0.00f;
    this->charge = 0.00f;
    this->chargeStop = 0.00f;
    this->armorPierce = 0.00f;
    this->shieldwallBlock = 0.00f;
    this->morale = 1.00f;
    this->stamina = 1.00f;
    this->defenseBroken = false;
    this->combatExperience = 0.00f;
    this->bHoldingLine = false;
    this->bFortified = false;
    this->bFireAtWill = false;
    this->bHoldFire = false;
    this->ClosestEnemyUnit = NULL;
    this->battleStance = false;
    this->closeProximity = false;
    this->fightingStance = false;
    this->inChargeDistance = false;
    this->locomotionStance = ELocomotionStance::Default;
    this->force1hAttacks = false;
    this->attackMethod = EAttackMethod::Mixed;
    this->repetitions = 0;
    this->targetRepetitions = 0;
    this->sprintMode = false;
    this->moveToEnemyRange = 3000000.00f;
    this->cosmeticEquipmentOverride = false;
    this->queuedItem = 0;
    this->animRandomVariation = 137;
    this->lastPlayedVariation = 0;
    this->shieldSymbolIndex = 0.00f;
    this->currentUnitRole = EUnitRole::Husband;
    this->assignedUnitRole = EUnitRole::Husband;
    this->pregnancy = 0.00f;
    this->Age = 1;
    this->meleeTraining = 0.00f;
    this->archeryTraining = 0.00f;
    this->surrounded = 0;
    this->exposed = 0;
    this->lastFiringTarget = NULL;
    this->spreadOut = false;
    this->friendlyFirePossible = false;
    this->friendlyFireAllowed = false;
    this->tacticalRetreat = false;
    this->engagementPercentage = 0.00f;
    this->DrawTime = 0;
    this->currentRegion = NULL;
    this->chosenPasture = NULL;
    this->mountAnimFlavour = 0;
    this->foundCommonLpath = false;
    this->unitsPassingThrough = false;
    this->unitsPassingSameDir = false;
    this->moveToFaceDot = 0.00f;
    this->moveRightDot = 0.00f;
    this->forceFacingForward = false;
    this->movingSideways = false;
    this->strafeRight = false;
    this->strafeLeft = false;
    this->walkForward = true;
    this->closeEnemyUpdateLag = 0;
    this->nearThresholdSq = 0.00f;
    this->animSpeedFac = 1.00f;
    this->squadAnyFriendlyFirePossible = false;
    this->animMode = EAnimMode::Work;
    this->instanceUpdateLag = 0;
    this->dropsTo = NULL;
    this->lastTradedWith = NULL;
    this->lastSoldTo = NULL;
    this->lastVeloUpdTime = 0.00f;
    this->raiding = false;
    this->itemsLooted = 0;
    this->regionUpdateTimer = 0;
    this->lastTrumpetTargetSquadID = 0;
    this->livestockRunawayTimer = 0;
    this->isBeingRallied = false;
    this->currAnimAction = 0;
    this->voiceID = 0;
    this->VAMPControllers.AddDefaulted(8);
    this->SpatialEntityComponent = NULL;
    this->currentAnimsetDT = NULL;
    this->currentAnimSpd = 1.00f;
    this->currentAnimSpdDefault = 1.00f;
    this->lastTransitionTime = 0.00f;
    this->previouslySetTransitionDuration = 0.20f;
    this->FinalYawCorrection = -90.00f;
    this->UniqueID = 0;
    this->assignedSquadID = 0;
    this->mountActor = NULL;
    this->isMount = false;
}

void ASMUnit::writeUnitDebugLog(const FString& newLogEntry) {
}

bool ASMUnit::useSkill(int32 skill) {
    return false;
}

void ASMUnit::updateTraits() {
}

void ASMUnit::updateSquadAnyFriendlyFirePossible() {
}

void ASMUnit::updateSquadAI() {
}

void ASMUnit::updateSpreadDist() {
}

ASMUnit* ASMUnit::updateNearestLazyFriend() {
    return NULL;
}

void ASMUnit::updateDecalVisibility() {
}

void ASMUnit::updateCurrentRegion(bool squadCenter) {
}

void ASMUnit::UnhideVAMPSlot(EEquipmentSlot Slot) {
}

bool ASMUnit::unequip(EEquipmentSlot Slot) {
    return false;
}

void ASMUnit::turnToSoldierJoinSquad(int32 squadToJoin) {
}

void ASMUnit::turnToBandit() {
}

void ASMUnit::triggerSquadRetreat() {
}

void ASMUnit::triggerEnemyCheer(ARegion* Region) {
}

void ASMUnit::step() {
}

void ASMUnit::squadRetreatAndReformIfClose() {
}

bool ASMUnit::squadOnPosition(const float& Percentage, bool excludeStragglers) {
    return false;
}

bool ASMUnit::squadIsTargetingThis(ASMUnit* unit) {
    return false;
}

bool ASMUnit::squadFinishedRecruiting() {
    return false;
}

void ASMUnit::spawnStaticGoodVisualization() {
}

void ASMUnit::SetVAMPVariationsToEquipment() {
}

void ASMUnit::setVAMPControllerCustomData(EEquipmentSlot equimentSlot) {
}

void ASMUnit::setVAMPColorSchemeUVsForSlot(EEquipmentSlot Slot, FVector newColorScheme) {
}

void ASMUnit::setTask(const FTask& newTask) {
}

void ASMUnit::setSprintModeWholeSquad(bool NewMode) {
}

bool ASMUnit::setSpreadOut_WholeSquad(const bool& newSetting) {
    return false;
}

void ASMUnit::setRetreatPositionWholeSquad() {
}

void ASMUnit::setRaidingWholeSquad(bool newSetting) {
}

void ASMUnit::setPushStance(const EPushStance& newStance, bool byMorale, bool playVoiceline) {
}

void ASMUnit::setFriendlyFireAllowedWholeSquad(const bool& newSetting) {
}

void ASMUnit::setFortified(bool newFortified) {
}

void ASMUnit::setCrossbowHolsterStateIfNeeded(bool holstered) {
}

void ASMUnit::setBehaviourStance(const EBehaviourStance& newStance, bool playVoiceline) {
}

void ASMUnit::removeFromSquad() {
}

void ASMUnit::removeFromFamilyIfHasOne(bool deleteEmptyFamily) {
}

void ASMUnit::playVfx(UParticleSystem* ParticleSystem, FName SocketName, FTransform Offset) {
}

void ASMUnit::playSoundCueFromDatabaseIfClose(FName cueName) {
}

void ASMUnit::playHitFx() {
}

void ASMUnit::playGruntFxSometimesIfClose() {
}

void ASMUnit::playGruntFxSometimes() {
}

void ASMUnit::pickRandomName() {
}

bool ASMUnit::pickNewShootingTarget() {
    return false;
}

bool ASMUnit::pickAttackAction(ASMUnit* targetUnit, bool backstab) {
    return false;
}

void ASMUnit::performHit() {
}

bool ASMUnit::ownsArtisanWorkshop() const {
    return false;
}

bool ASMUnit::murderVillagersNear(const FVector& Position, float maxDistSq) {
    return false;
}

void ASMUnit::just_die() {
}

bool ASMUnit::isWagonEquipped() {
    return false;
}

bool ASMUnit::isVAMPControllerVisibile(EEquipmentSlot equimentSlot) {
    return false;
}

bool ASMUnit::isUnitWithinMapBounds() {
    return false;
}

bool ASMUnit::isSquadFleeing() {
    return false;
}

bool ASMUnit::isSquadEngaged() {
    return false;
}

bool ASMUnit::IsSpatiallyVisible() {
    return false;
}

bool ASMUnit::isSoldier() const {
    return false;
}

bool ASMUnit::isSkillAvailable(int32 skillID, TArray<FName>& outReasonsNot) {
    return false;
}

bool ASMUnit::isSkillActive(int32 skillID) {
    return false;
}

bool ASMUnit::isRangedUnit() {
    return false;
}

bool ASMUnit::isPloughEquipped() {
    return false;
}

bool ASMUnit::isHumanCivilian(bool includeRetainers) {
    return false;
}

bool ASMUnit::isFamilyInjured() {
    return false;
}

bool ASMUnit::isFamilyHead() {
    return false;
}

bool ASMUnit::isFamilyDiseased() {
    return false;
}

bool ASMUnit::isEquipped(int32 ItemType) {
    return false;
}

bool ASMUnit::isDisbanded() {
    return false;
}

bool ASMUnit::inEditor() {
    return false;
}

void ASMUnit::HideVAMPSlot(EEquipmentSlot Slot) {
}

void ASMUnit::hideVAMPControllers() {
}

bool ASMUnit::hasValidFamily() const {
    return false;
}

bool ASMUnit::hasNoFamilyMembers() {
    return false;
}

ASMBuildingMaster* ASMUnit::getWorkplace() const {
    return NULL;
}

int32 ASMUnit::getVoiceID() {
    return 0;
}

uint8 ASMUnit::getVAMPTextureVariationIDForSlot(EEquipmentSlot Slot) const {
    return 0;
}

uint8 ASMUnit::getVAMPMeshVariationIDForSlot(EEquipmentSlot Slot) const {
    return 0;
}

UVAISMControllerAbstract* ASMUnit::getVAMPController(EEquipmentSlot Slot) {
    return NULL;
}

FVector ASMUnit::getVAMPColorSchemeUVsForSlot(EEquipmentSlot Slot) const {
    return FVector{};
}

FName ASMUnit::getUnitSquadTemplateName() {
    return NAME_None;
}

TArray<ASMUnit*> ASMUnit::getUnitsBlockingLine(const FSegment2D& line, const TArray<ASMUnit*> unitsToCheck, const int32& skipID, APawnCPP* onlyOwner) {
    return TArray<ASMUnit*>();
}

int32 ASMUnit::getTradeRouteMerchantsTradingGoodType() {
    return 0;
}

FName ASMUnit::getTaskLabel() {
    return NAME_None;
}

FVector ASMUnit::getTargetPos() {
    return FVector{};
}

TArray<FName> ASMUnit::getStatus() {
    return TArray<FName>();
}

TArray<ASMUnit*> ASMUnit::GetSquadUnits() {
    return TArray<ASMUnit*>();
}

TArray<EUnitTrait> ASMUnit::getSquadTraits() {
    return TArray<EUnitTrait>();
}

ASMUnit* ASMUnit::getSquadLeader() {
    return NULL;
}

float ASMUnit::getSquadFormationSpread() {
    return 0.0f;
}

FVector ASMUnit::getSquadCenter() {
    return FVector{};
}

TArray<FName> ASMUnit::getSquadAudioTags() {
    return TArray<FName>();
}

int32 ASMUnit::getJobType() const {
    return 0;
}

FName ASMUnit::getItemVariationName(int32 goodID) {
    return NAME_None;
}

EEquipmentSlot ASMUnit::getItemEquipmentSlot(int32 ItemId, bool useCarryingVariationIfPossible) {
    return EEquipmentSlot::Body;
}

FVector ASMUnit::GetInterpolatedLocation() const {
    return FVector{};
}

ASMBuildingMaster* ASMUnit::getHome() {
    return NULL;
}

ASMBuildingMaster* ASMUnit::getFamilyStall() {
    return NULL;
}

int32 ASMUnit::getFamilyLevel() {
    return 0;
}

int32 ASMUnit::GetEquippedID(EEquipmentSlot Slot) {
    return 0;
}

TArray<ASMUnit*> ASMUnit::getEnemyUnitsInShootingRange(const int32& targetSquad, bool& friendlyFire) {
    return TArray<ASMUnit*>();
}

bool ASMUnit::getDebugFlag(FName flagName) {
    return false;
}

FUnitDataStruct ASMUnit::getData() {
    return FUnitDataStruct{};
}

FName ASMUnit::getCurrentEquipmentVariation(EEquipmentSlot equimentSlot) {
    return NAME_None;
}

ASMUnit* ASMUnit::getBlockingLineVision(ASMUnit* unitA, ASMUnit* unitB) {
    return NULL;
}

TArray<ASMUnit*> ASMUnit::getAllFamilyMembers() {
    return TArray<ASMUnit*>();
}

AResource* ASMUnit::FindNearestCart(const ASMBuildingMaster* belongsTo) {
    return NULL;
}

bool ASMUnit::faceEnemy(bool clampRotation) {
    return false;
}

void ASMUnit::equipWithAnimation(const int32& ItemType) {
}

void ASMUnit::equipTradeWagon() {
}

bool ASMUnit::equipResource(int32 goodID, bool freeHands) {
    return false;
}

void ASMUnit::equipFromTemplate(const FUnitTemplate& Temp, const FName& tempName, bool bannerCarrier) {
}

bool ASMUnit::equipCosmeticOnly(int32 goodID) {
    return false;
}

void ASMUnit::equipAdequateCivilianClothes(bool forceChange) {
}

bool ASMUnit::equip(int32 goodID, bool forceChange, bool useCarryingVariationIfPossible) {
    return false;
}

void ASMUnit::drawDebugBoxAtLocation(const FVector& Location, FColor boxColor, float boxTime, FVector BoxSize) {
}

void ASMUnit::DrawDebugBox(FName debugFlag, FColor boxColor, float boxTime, FVector BoxSize) {
}

bool ASMUnit::doFarmingJobs(bool autoHarvestOnly, bool neverIgnoreWorkerLimit) {
    return false;
}

void ASMUnit::despawnStaticGoodVisualization() {
}

void ASMUnit::despawnAllStaticGoodVisualizations() {
}

void ASMUnit::deathAnimationEnded() {
}

void ASMUnit::CombatHit(ASMUnit* attacker, ASMUnit* defender, bool isProjectile, float projDist, bool avoidKilling) {
}

void ASMUnit::changeMapVariationID(TMap<EEquipmentSlot, uint8>& variationMap, EEquipmentSlot Slot, int32 change) {
}

void ASMUnit::changeEquipmentVariation(EEquipmentSlot Slot, FName VariationName) {
}

void ASMUnit::cartLoadingUnequipGood() {
}

void ASMUnit::cartLoadingEquipGood() {
}

bool ASMUnit::capSpeedToPersonInFront(const FVector& currentLocation, const FVector& ProjectedLocation) {
    return false;
}

bool ASMUnit::canSetPushStance(const EPushStance& stanceType) {
    return false;
}

bool ASMUnit::canBeTrampled(ASMUnit* unit) {
    return false;
}

void ASMUnit::calculateMorale(float adjustedTimeDelta) {
}

bool ASMUnit::anyoneFiringAlready() {
    return false;
}

bool ASMUnit::anyActionInSquad(const int32& actionID) {
    return false;
}

void ASMUnit::animationLoopEnded(bool intraLoop) {
}


