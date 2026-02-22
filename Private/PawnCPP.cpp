#include "PawnCPP.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=CameraComponent -FallbackName=CameraComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SpringArmComponent -FallbackName=SpringArmComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "ControlHook.h"

APawnCPP::APawnCPP(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->masterPtr = NULL;
    this->isMainPlayer = false;
    this->isAI = false;
    this->bCinematicTime = false;
    this->Boom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Boom"));
    this->Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    this->cameraHeightMin = 200.00f;
    this->cameraHeightMax = 4000.00f;
    this->zoomLevel = 0.00f;
    this->smoothZoomLevel = 0.00f;
    this->smoothZoomIncr = 0.00f;
    this->b_ctrl_pressed = false;
    this->shift_pressed_b = false;
    this->b_tab_pressed = false;
    this->alt_pressed_b = false;
    this->RMB_pressed_b = false;
    this->LMB_pressed_b = false;
    this->MMB_pressed_b = false;
    this->cameraRotateAxisValue = 0.00f;
    this->hoverUnit = NULL;
    this->bHoversEnemy = false;
    this->hoverSquadID = 0;
    this->isUsingUI = false;
    this->ControlHook = CreateDefaultSubobject<UControlHook>(TEXT("ControlHook"));
    this->MPC = NULL;
    this->cursorMode = ECursorMode::Default;
    this->placeBuilding = 0;
    this->bbox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DummyBuilding"));
    this->workAreaPreviewRange = 0.00f;
    this->workAreaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("workAreaMesh"));
    this->rangeDecal = NULL;
    this->roadDecal = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("roadDecal_Mesh"));
    this->roadPosDecalMat = NULL;
    this->roadPosDecalMatOnRoad = NULL;
    this->buildingPreviewDecalMat = NULL;
    this->extensionPreviewDecalMat = NULL;
    this->marketPreviewDecalMat = NULL;
    this->bPartPreviewDecalMat = NULL;
    this->moveArrow = NULL;
    this->BoundsDecal = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildingBoundsPreview"));
    this->circularBoundsDecalMat = NULL;
    this->boundsDecalMat_Military = NULL;
    this->hitBuilding = NULL;
    this->hitBuildingPart = NULL;
    this->lastZoomLevelProximityCacheUpdate = 0.00f;
    this->dummyRoad = NULL;
    this->roadmode = false;
    this->roadRemoveMode = false;
    this->roadStarted = false;
    this->roadBuildHover = false;
    this->hoverRoad = NULL;
    this->plannerModeBld = NULL;
    this->inPlanningMode = false;
    this->hoverBlueprint = NULL;
    this->selectedBlueprint = NULL;
    this->draggingBlueprint = NULL;
    this->draggingRoadPointID = 0;
    this->isDraggingGatePoint = false;
    this->rotationGizmo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("rotationGizmo_Mesh"));
    this->rotationGizmo_startYaw = 0.00f;
    this->isDraggingRotationGizmo = false;
    this->isRotationGizmoHovered = false;
    this->rotationGizmo_smoothOpacity = 0.00f;
    this->RT_modulePlanner = NULL;
    this->hasClicked = false;
    this->letterCreatorMode = false;
    this->mapLerp = 0.00f;
    this->bIsPlayerPaused = false;
    this->currentRegion = NULL;
    this->regionUnderCursor = NULL;
    this->markLoyaltyUIUpdate = false;
    this->numFieldDrainage = 0;
    this->camera_tilt = 0.00f;
    this->camera_heightOffset = 0.00f;
    this->camera_clearance = 0.00f;
    this->roadTangentScale = 0.00f;
    this->silver = 0;
    this->currentUIMode = EMainUIMode::Gameplay;
    this->cinematicMode = false;
    this->followMode = false;
    this->following = NULL;
    this->tabBeforeSwitch = 0;
    this->roadCurvatureBarOpacity = 0.00f;
    this->bRoadCurvatureChanged = false;
    this->mapViewMode = false;
    this->mapViewDist = 25000.00f;
    this->mapViewSpeedMul = 1.00f;
    this->hoveringRegion = NULL;
    this->selectedRegion = NULL;
    this->recruitCost = 0.00f;
    this->lastActionTime = 0.00f;
    this->lastQuestDay = 0;
    this->isBandit = false;
    this->influence = 0;
    this->targetSquadSize = 5;
    this->maxNumOfMilitiaToSpawn = 6;
    this->cameraMoved = false;
    this->cameraRotated = false;
    this->cameraZoomed = false;
    this->wallMode = false;
    this->bRelationsEstablishd = false;
    this->placeBuilding_isSnapped = false;
    this->placeBuilding_snapVariation = 0;
    this->isFemale = false;
    this->Portrait = NULL;
    this->kingsFavour = 0;
    this->predictedIncome = 0;
    this->lastShoutSfx = 0.00f;
    this->shouldUpdateArmyUI = false;
    this->shouldUpdateArmyListUI = false;
    this->shouldUpdateStatUI = false;
    this->RegionPanelTarget = NULL;
    this->RegionPanel_GoodListUpdateType = EQueuedUIUpdateType::RegionalSurplus;
    this->shouldUpdateProblemUI = false;
    this->shouldUpdateClaimUI = false;
    this->shouldUpdateApprovalUI = false;
    this->shouldUpdateInventoryStorageUI = false;
    this->shouldUpdateResidentsUI = false;
    this->bShouldUpdateLivingSpaceUI = false;
    this->lastIconClickTime = 0.00f;
    this->firingRangeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("firingRangeMesh"));
    this->firingRangeDynamicMaterial = NULL;
    this->firingRangeVisible = false;
    this->firingRangeOpacity = 0.00f;
    this->unitDecalDynamic = NULL;
    this->unitDecalDynamic_selected = NULL;
    this->weather_thunderStorm = false;
    this->DMS_battleIntensity = 0.00f;
    this->DMS_tacticalRetreat = 0.00f;
    this->LMB_last_pressed_time = 0.00f;
    this->doubleclick_threshold = 0.20f;
    this->placePlotType = EPlotType::None;
    this->placeFieldMode = false;
    this->isMarket = false;
    this->isExtension = false;
    this->extensionFor = NULL;
    this->fieldCollides = false;
    this->fieldClosed = false;
    this->fieldWorkersNeeded = 0;
    this->minimumBuildDistanceFromBorder = 650.00f;
    this->isInsideBorders = true;
    this->fieldPointsChanged = true;
    this->slicingAngle = 0;
    this->numPlotOffset = 0;
    this->expectedNumPlots = 1;
    this->maxDivisionsForThisPlot = 1;
    this->fieldSpline_StaticMesh = NULL;
    this->M_fieldSplineDummy = NULL;
    this->hoverProblem = 0;
    this->buildingPreviewPlane = NULL;
    this->marketShape = 0;
    this->tooltipTint = ETooltipTint::White;
    this->predictedRoyalTaxes = 0;
    this->numTimesInDebt = 0;
    this->movedBuilding = NULL;
    this->markerAnimationTimes.AddDefaulted(4);
    this->SM_fieldMarker = NULL;
    this->bHoversRoadCommit = false;
    this->buildConfirmHovered = false;
    this->whiteTooltipCorner = 0;
    this->commitFieldRequestPending = false;
    this->upgradeRequestPending = false;
    this->artisanChangeRequestPending = false;
    this->extensionChangeRequestPending = false;
    this->requestBuild = false;
    this->hasAnyActiveQuests = false;
    this->foliageTransparencyAdd = 0.00f;
    this->debugBoopMode = false;
    this->reassignMode_FamilyMember = NULL;
    this->cameraLerpFrames = 0.00f;
    this->wallCursor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("wallCursor"));
    this->DT_Alerts = NULL;
    this->smoothedConstrMode = 0.00f;
    this->dipToBlackOpacity = 1.00f;
    this->currentCinematicShotElapsedTime = 0.00f;
    this->cinematicOverEvent = ECinematicEvent::Continue;
    this->grayscaleTint = false;
    this->plotToRoadSnappingHelperStaticMesh = NULL;
    this->timeMarketDistributionHovered = 0.00f;
    this->bMarketDistributionShowing = false;
    this->marketDistributionOverlayCategory = EResidentialRequirement::Water;
    this->marketDistributionOverlaySubcategory = EItemSubcategory::None;
    this->marketResourceIconBgTexture = NULL;
    this->shouldUpdateMarketStats = false;
    this->activeRTSTool = ERTSTool::None;
    this->RTSToolActor = NULL;
    this->squadPathArrowMesh = NULL;
    this->Boom->SetupAttachment(RootComponent);
    this->Camera->SetupAttachment(Boom);
    this->roadDecal->SetupAttachment(RootComponent);
    this->wallCursor->SetupAttachment(RootComponent);
}

void APawnCPP::withdrawAllClaimsAndChallengesTowards(APawnCPP* Pawn) {
}

bool APawnCPP::wasParagraphEverUsed(APawnCPP* sender, const FName& para) {
    return false;
}

void APawnCPP::updateTradeUI_Implementation() {
}

void APawnCPP::updateTownLabels_Implementation() {
}

void APawnCPP::updateTooltip() {
}

void APawnCPP::updateStatUI_Implementation() {
}

void APawnCPP::updateSquadVisibility() {
}

void APawnCPP::updateSoundFilters_Implementation() {
}

void APawnCPP::updateShowDecalSquads() {
}

void APawnCPP::updateSelectionDecals(TArray<ASMUnit*> unitsToUpdate) {
}

void APawnCPP::updateRTSToolActorUI_Implementation() {
}

void APawnCPP::updateRoadDecalVisibility() {
}

void APawnCPP::UpdateRetinuePreviewMeshTransform() {
}

void APawnCPP::updateResourceOutlines() {
}

void APawnCPP::updateResidentsUI_Implementation() {
}

void APawnCPP::updateRecruitmentPool() {
}

void APawnCPP::updateQuestTimesUI_Implementation() {
}

void APawnCPP::updateQuestlog_Implementation() {
}

void APawnCPP::updateProjectedFieldCollision(bool checkSteepness, bool reprojectNoSnapIfCollides) {
}

void APawnCPP::updateProblemUI_Implementation() {
}

void APawnCPP::updatePreviewRoadDecalsPos() {
}

void APawnCPP::updatePreviewBuildingDecalsPos() {
}

void APawnCPP::updatePlotToRoadSnappingHelperLocations() {
}

void APawnCPP::updatePlacebuildingMPC() {
}

void APawnCPP::updatePlacebuildingMesh_Implementation(int32 buildingID, bool isSnapped, int32 snapVariationID) {
}

void APawnCPP::updateOverlayDecalVisibility() {
}

void APawnCPP::updateOrderProgressUI_Implementation(const ASMBuildingMaster* building) {
}

void APawnCPP::updateMercenayCompanyUI_Implementation() {
}

void APawnCPP::updateMarketStats_Implementation() {
}

void APawnCPP::updateLogUI_Implementation() {
}


void APawnCPP::updateKingsFavourUI_Implementation() {
}

void APawnCPP::updateInventoryStorage_Implementation() {
}

void APawnCPP::updateInventoryFieldStatus_Implementation() {
}

void APawnCPP::updateInventory_Implementation(const EUpdateType UpdateType) {
}

void APawnCPP::updateHoveringRegion() {
}

void APawnCPP::updateHasAnyActiveQuests() {
}

void APawnCPP::updateGameSpeedUI_Implementation() {
}

void APawnCPP::updateFieldPointMarkers() {
}

void APawnCPP::updateDiplomaticTags() {
}


void APawnCPP::updateDateUI_Implementation(int32 day, int32 Month, int32 season) {
}

void APawnCPP::updateCursor(ECursorMode NewMode) {
}

void APawnCPP::updateCurrentRegionUI_Implementation() {
}

void APawnCPP::updateCurrentRegion() {
}

void APawnCPP::updateCommandedAndEnemySquads(bool includeFleeing) {
}

void APawnCPP::updateCoatOfArmsSymbol_Implementation() {
}

void APawnCPP::updateClaimsUI_Implementation() {
}

void APawnCPP::updateClaims() {
}

void APawnCPP::updateClaimBlocked(FClaim& Claim) {
}

void APawnCPP::updateCastleReconstructionCostUI_Implementation() {
}


void APawnCPP::updateCameraClearance() {
}

void APawnCPP::UpdateBuildingProximityCache() {
}

void APawnCPP::updateBoopMode_Implementation() {
}

void APawnCPP::updateAssignModeUI_Implementation() {
}

void APawnCPP::updateApprovalUI_Implementation() {
}


void APawnCPP::updateActiveRTSToolUI_Implementation() {
}

void APawnCPP::unPauseGame() {
}

void APawnCPP::triggerTutorialIfNeeded_Implementation(FName tutorialMsg, const FVector& Location) {
}

void APawnCPP::triggerDefeat(const FName& EventTag, APawnCPP* byWho) {
}

void APawnCPP::toggleTimePause_Implementation() {
}

void APawnCPP::toggleTimeNext_Implementation() {
}

void APawnCPP::toggleSprint() {
}

void APawnCPP::togglePauseMenu_Implementation() {
}

void APawnCPP::tickCinematicShot(float DeltaTime) {
}



void APawnCPP::tab_released() {
}

void APawnCPP::tab_pressed() {
}

void APawnCPP::switchWallMode(const bool& NewMode) {
}

void APawnCPP::switchTab_Implementation(const int32& Tab) {
}

void APawnCPP::stopVAMP() {
}

bool APawnCPP::splitWallsByCastleModule(const AStaticMeshActor* Actor) {
    return false;
}

void APawnCPP::spawnWorkAreaConfirmation_Implementation(const FVector& Pos, const float& Radius) {
}


void APawnCPP::spawnPlotToRoadSnappingHelperLocations(int32 numHelpers) {
}



void APawnCPP::showProgressUpdate_Implementation(ARegion* Region) {
}

bool APawnCPP::shouldShowFieldPreview() {
    return false;
}

void APawnCPP::setWorkAreaMode(ASMBuildingMaster* building) {
}

void APawnCPP::setUIScale(float NewScale) {
}

void APawnCPP::settleRegion(ARegion* regionToSettle, const FTransform& SettlersCampLocation, uint8 supplyLevel, ESettlementType settlementType, ARegion* outpostToRegion) {
}

void APawnCPP::setSquadName(int32 squadID, const FString& NewName) {
}

void APawnCPP::setShowPlotToRoadSnappingHelpers(bool shouldShow) {
}

void APawnCPP::SetSettings(FGlobalSettings newSettings) {
}

void APawnCPP::setRoadMode(bool Mode, FVector StartPos, bool Started) {
}

void APawnCPP::setReassignMode(ASMUnit* FamilyMember) {
}

void APawnCPP::SetPreviewWorkAreaMode(ASMBuildingMaster* building) {
}

void APawnCPP::SetPosition(const FVector& newPos) {
}

void APawnCPP::setPlannerMode(ASMBuildingMaster* setPlannerBuilding) {
}

void APawnCPP::setPlaceRallyingPoint(TArray<int32> squadIDs) {
}

void APawnCPP::setPlacedBuilding(int32 newPlacedBuilding) {
}

void APawnCPP::setMapMode(const bool& newMapMode) {
}

void APawnCPP::setMapLerp(const float& NewValue) {
}

void APawnCPP::setMainUIMode_Implementation(EMainUIMode NewMode) {
}

void APawnCPP::setLocationAboveGround(FVector& NewPosition, float DeltaTime) {
}

void APawnCPP::SetLMBReleased(bool isLMBReleased) {
}

void APawnCPP::setLetterCreatorMode(const bool NewMode) {
}

void APawnCPP::setIsUsingUI(bool newFlag) {
}

void APawnCPP::setIsUsingLowTopBars(const bool& newFlag) {
}


void APawnCPP::SetGoodCounterWidget(int32 goodType, bool bAlternativeWidget, UTextBlock* WidgetToSet) {
}

void APawnCPP::setGameSpeed(const float newSpeed) {
}

void APawnCPP::setFollowMode(AActor* actorToFollow, bool playSfx) {
}

void APawnCPP::setFieldMode(bool NewMode, bool _isExtension, bool _isMarket, EPlotType plotType) {
}

void APawnCPP::setDipToBlackOpacity_Implementation(float Opacity) {
}

void APawnCPP::setCinematicMode_Implementation(bool NewMode) {
}

void APawnCPP::setChoice(FName newChoice, int32 questID) {
}

void APawnCPP::SetCategoryCounterWidget(EItemCategory Category, UTextBlock* WidgetToSet) {
}

void APawnCPP::setBuildingSelected(ASMBuildingMaster* building, bool newSelected) {
}

void APawnCPP::setBuildingMesh(UStaticMesh* Mesh) {
}

void APawnCPP::setBorderVisibility(bool newSetting) {
}

void APawnCPP::setAllBuildingMeshesHidden(bool hidden) {
}

void APawnCPP::sendLetter(APawnCPP* recipient, const TArray<FName>& Letter) {
}

void APawnCPP::selectSquad(int32 squadID, bool resetSelection, bool playSounds) {
}

void APawnCPP::selectHoveredBuilding() {
}

void APawnCPP::selectCastleBlueprint(AActor* Blueprint, bool turnOnFollowMode) {
}

void APawnCPP::selectBuildingSilent(ASMBuildingMaster* bld) {
}

void APawnCPP::saveScreenshot() {
}

void APawnCPP::RMB_BP_released_Implementation() {
}

void APawnCPP::RMB_BP_pressed_Implementation() {
}

void APawnCPP::ReverseSelectedWall() {
}

void APawnCPP::respawnTownNames_Implementation() {
}

void APawnCPP::respawnSquadPathArrows(int32 squadID) {
}

void APawnCPP::respawnPreviewRoadDecals() {
}

void APawnCPP::respawnPreviewBuildingDecals() {
}

bool APawnCPP::requestSaveFile(const FString& SlotName, const FString& saveName) {
    return false;
}

void APawnCPP::reorderUnitCard(int32 squadID, int32 newIndex) {
}

void APawnCPP::renameSquad(int32 squadID, const FString& NewName) {
}

void APawnCPP::removeSquad(int32 squadID) {
}

void APawnCPP::removeRoad(ARoad* roadToRemove) {
}

void APawnCPP::removeOpportunity(FQuest opportunityToRemove) {
}

void APawnCPP::removeLogEntry(const FLogEntry& Entry) {
}

void APawnCPP::removeLastRoadPoint() {
}

void APawnCPP::removeChallengeFromUI_Implementation(int32 challengeID) {
}

void APawnCPP::refuteClaim(FClaim& claimToRefute, bool useFavour) {
}

void APawnCPP::refuseQuest(const FQuest& Quest) {
}

void APawnCPP::recalculateRoyalTaxes() {
}

void APawnCPP::rallySquads(TArray<int32> squadIDs, FTransform rallyPointTransform) {
}

void APawnCPP::QuestMessage_Implementation(const FQuest& Quest) {
}

void APawnCPP::projectResidentialAndUpdateUI() {
}

void APawnCPP::projectMarketplace() {
}

void APawnCPP::projectHoldSquad(int32 squadID) {
}

void APawnCPP::projectFormation(int32 squadID, const FVector& Pos, const FVector& sourceOverride, const FVector& facingTargetOverride) {
}

void APawnCPP::projectField(bool snap) {
}

void APawnCPP::projectCircularBorder(const FVector& Center, float diameter, TArray<FVector>& outSmoothBorder, TArray<FVector>& outBorder) {
}

void APawnCPP::projectAttackFormation(TArray<ASMUnit*> attackers, TArray<ASMUnit*> defenders, bool alwaysDirect) {
}

void APawnCPP::projectArmyFormation(const TArray<int32>& squads, const FVector& Pos, FVector sourceOverride, const uint8 floor) {
}

void APawnCPP::positionRoadConfirm_Implementation(const FVector& NewPosition) {
}

void APawnCPP::pleaseTurnMapView_Implementation(bool NewMode) {
}

void APawnCPP::playVoiceResponse_Implementation(const FName& responseKey, const int32& voiceID, ASMUnit* relatedUnit) {
}

void APawnCPP::playVoiceline(const TArray<FName>& audioTags, const FVector& Pos, bool allowOverlap) {
}

void APawnCPP::playUISnd_Implementation(int32 Type) {
}


void APawnCPP::playQuestMessage_Implementation(const FQuest& Quest) {
}

void APawnCPP::playPopupMessageIfNotPlayedRecently(FName MessageType, ARegion* Region) {
}

void APawnCPP::playPopupMessageGUI_Implementation(FName MessageType, ARegion* Region) {
}

void APawnCPP::playParticleSystem_Implementation(const int32& ID, const FVector& Pos) {
}

void APawnCPP::playMessage_Implementation(FQuestMessage Message, const int32& questID) {
}

void APawnCPP::playMarkerSound_Implementation(const int32& snd) {
}

void APawnCPP::playKillCam_Implementation(const FVector& Pos) {
}

void APawnCPP::playFeedbackText_Implementation(const FString& Text, const FVector& Pos, float Speed) {
}

void APawnCPP::playEventMessage_Implementation(const FName& msgType, const FString& primaryText, const FString& secondaryText) {
}

void APawnCPP::playEventComplexMessage_Implementation(const FName& msgType, const TArray<FString>& primaryText, const TArray<FString>& secondaryText) {
}

void APawnCPP::playCinematicSequence(TArray<FCinematicShot> shotSequence, ECinematicEvent afterItsOver) {
}

void APawnCPP::playCameraShake_Implementation(const int32& typeOfShake, AActor* DebugActor, const FString& Reason) {
}

void APawnCPP::playBuildingSound_Implementation(const int32& bType) {
}

void APawnCPP::playBuildEffects_Implementation(const FVector& Position) {
}

void APawnCPP::playAlertFromTag(FName alertTag) {
}

void APawnCPP::playAlert_Implementation(const int32& Type) {
}

void APawnCPP::placeFieldDummy(bool forceChange) {
}

FName APawnCPP::pickVoiceResponse(ASMUnit* peasant, bool rare) {
    return NAME_None;
}

void APawnCPP::performCustomQuestTriggers(const TArray<FName>& triggerNames, APawnCPP* recipient) {
}

void APawnCPP::pauseGame() {
}

void APawnCPP::PaperMapViewChanged(bool bIsPaperMap) {
}

void APawnCPP::openSettlementInitializer_Implementation(ARegion* Region) {
}

void APawnCPP::openCastlePlannerUI_Implementation(ASMBuildingMaster* plannerBuilding) {
}

void APawnCPP::openBuildingTab_Implementation(ASMBuildingMaster* building, bool playSfx) {
}

void APawnCPP::OnWindowFocusChanged_Implementation(bool bIsFocused) {
}

void APawnCPP::onSavingFinished() {
}

float APawnCPP::measureSquadPowerFromTemplate(FName& UnitTemplate) {
    return 0.0f;
}

float APawnCPP::measureSquadPower(const int32& squadID, bool onlyMelee) const {
    return 0.0f;
}

void APawnCPP::MarkLogIndexAsDisplayed(const int32 Index) {
}

bool APawnCPP::logExists(const FLogEntry& LogEntry, bool includeDismissed) {
    return false;
}

void APawnCPP::LMB_BP_released_Implementation() {
}

void APawnCPP::LMB_BP_pressed_Implementation() {
}

bool APawnCPP::letter_hasAnyParagraphs(const TArray<FName>& currentLetter, const TArray<FName>& paras) {
    return false;
}

bool APawnCPP::letter_hasAllRequired(const TArray<FName>& currentLetter, const TArray<FName>& requiredParas) {
    return false;
}

bool APawnCPP::letter_containsPara(const TArray<FName>& currentLetter, const FName& para) {
    return false;
}

void APawnCPP::layClaim(ARegion* Region, bool useFavour, bool consumeInfluence) {
}

bool APawnCPP::joinWalls(ARoad* wallA, ARoad* wallB) {
    return false;
}

bool APawnCPP::isTaxFixed(int32 taxTypeID) {
    return false;
}

void APawnCPP::issueRaiderTrackingQuestIfNew(int32 daysUntilRaid) {
}

bool APawnCPP::isStanceActivatedForSelected(bool isPushStance, const EPushStance& _pushStance, const EBehaviourStance& _behaviourStance) {
    return false;
}

bool APawnCPP::isSquadSelected(int32 squadID) {
    return false;
}

bool APawnCPP::isSquadFleeing(int32 squadID) {
    return false;
}

bool APawnCPP::isSkillAvailableForSelectedSquads(int32 skillID, TArray<FName>& outReasonsNot) {
    return false;
}

bool APawnCPP::IsSelectEnemyBuildingOverrideEnabled() {
    return false;
}

bool APawnCPP::isRoadGuidePoint(const FVector& Point) {
    return false;
}

bool APawnCPP::isInAnyConstructionMode() {
    return false;
}

bool APawnCPP::isCurrentlyInBattle() {
    return false;
}

bool APawnCPP::isBuildingHovered() {
    return false;
}

bool APawnCPP::isAnySquadRaiding(const FArmy& Army) {
    return false;
}

void APawnCPP::invokeRemoveRoadPrompt_Implementation(ARoad* roadToRemove) {
}

void APawnCPP::iconPop_Implementation(ASMBuildingMaster* building, int32 Type) {
}

int32 APawnCPP::howManyDayAgoSentParagraph(const FName& para, APawnCPP* recipient) {
    return 0;
}

void APawnCPP::HomeShortcut_pressed_Implementation() {
}

void APawnCPP::highlightTargetBuilding_Implementation(ASMBuildingMaster* building) {
}

bool APawnCPP::hasTechAnyRegion(const int32& ID, int32 tier) {
    return false;
}

bool APawnCPP::hasActiveQuestNamed(const FString& questName) {
    return false;
}

bool APawnCPP::getWorkAreaMode() {
    return false;
}

FVector APawnCPP::getWallJoiningLocation(const ARoad* wallA, const ARoad* wallB) {
    return FVector{};
}

float APawnCPP::getUIScale() {
    return 0.0f;
}

TArray<FTradepoint> APawnCPP::getTradeDeals() {
    return TArray<FTradepoint>();
}

float APawnCPP::getTotalRecruitmentCost(const TArray<FName>& recruitment) {
    return 0.0f;
}

FVector2D APawnCPP::getTaxRange(int32 taxTypeID) {
    return FVector2D{};
}

TArray<ASMUnit*> APawnCPP::GetSquadUnits(const int32& squadID) {
    return TArray<ASMUnit*>();
}

FName APawnCPP::getSquadStatus(const int32& squadID) {
    return NAME_None;
}

TArray<int32> APawnCPP::getSquadsNearPos(const FVector& Pos, const float& rangeSq, const TArray<int32>& squads) {
    return TArray<int32>();
}

APawnCPP* APawnCPP::getSquadOwner(const int32& squadID) {
    return NULL;
}

int32 APawnCPP::getSquadEquipmentAmt(int32 squadID, int32 goodType) {
    return 0;
}

TArray<int32> APawnCPP::getSquadControlGroups(int32 squadID) {
    return TArray<int32>();
}

FString APawnCPP::getSquadCompanyName(int32 squadID) const {
    return TEXT("");
}

FSquad APawnCPP::getSquadByID(int32 squadID) {
    return FSquad{};
}

TArray<FString> APawnCPP::getSmallTooltip() {
    return TArray<FString>();
}

FString APawnCPP::getSetupPortraitName() {
    return TEXT("");
}

FGlobalSettings APawnCPP::getSettings() {
    return FGlobalSettings{};
}

TArray<ASMBuildingMaster*> APawnCPP::getSelectedBuildings() {
    return TArray<ASMBuildingMaster*>();
}

int32 APawnCPP::getSelectedBuildingBlueprintUpgradeLevel(int32& buildingType, EWallType& wallType) const {
    return 0;
}

TArray<ASMUnit*> APawnCPP::GetSelected() {
    return TArray<ASMUnit*>();
}

float APawnCPP::getRoadTangentScale() {
    return 0.0f;
}

bool APawnCPP::getRoadMode() const {
    return false;
}

ERallyingStatus APawnCPP::getRetinueRallyingStatus(ARegion* Region) {
    return ERallyingStatus::Disbanded;
}

TArray<ARegion*> APawnCPP::getRelevantClaimedRegions(bool includeChallenges) {
    return TArray<ARegion*>();
}

TArray<FChallenge> APawnCPP::getRelevantChallenges() {
    return TArray<FChallenge>();
}

int32 APawnCPP::getRelationsWith(APawnCPP* Pawn) {
    return 0;
}

bool APawnCPP::getRectB() {
    return false;
}

FVector2D APawnCPP::getRect() {
    return FVector2D{};
}

TArray<FName> APawnCPP::getRecruitmentPool(bool mercenaries) {
    return TArray<FName>();
}

TArray<FQuest> APawnCPP::getQuestsWithFocus(FName focus) {
    return TArray<FQuest>();
}

TArray<FQuest> APawnCPP::getQuests() {
    return TArray<FQuest>();
}

bool APawnCPP::getPreviousLetterFromThisPawn(APawnCPP* Pawn, FLetter& Letter) {
    return false;
}

bool APawnCPP::getPreviousLetterFromConversation(APawnCPP* Pawn, FLetter& Letter) {
    return false;
}

ARegion* APawnCPP::getPreviousCommandedRegion(ARegion* InCurrentRegion) {
    return NULL;
}

TArray<ASMUnit*> APawnCPP::getPlayersOxen() {
    return TArray<ASMUnit*>();
}

int32 APawnCPP::getPawnSetupIndex() {
    return 0;
}

TArray<int32> APawnCPP::getOrderedSquadList() {
    return TArray<int32>();
}

int32 APawnCPP::getNumYearsSurvived() {
    return 0;
}

void APawnCPP::getNumShowingQuestMessages_Implementation(int32& Num) {
}

bool APawnCPP::getNextProblemOfType(const int32& Type, FProblem& outProblem, ARegion* Region) {
    return false;
}

ARegion* APawnCPP::getNextCommandedRegion(ARegion* InCurrentRegion) {
    return NULL;
}

FVector APawnCPP::getNearestRoadLocation() {
    return FVector{};
}

float APawnCPP::getMouseLMBdist() {
    return 0.0f;
}

FVector APawnCPP::getMouse3d() {
    return FVector{};
}

FVector2D APawnCPP::getMouse() {
    return FVector2D{};
}

int32 APawnCPP::getMonthIDFromWeatherMaster() {
    return 0;
}

bool APawnCPP::getMapMode() {
    return false;
}

TArray<ASMBuildingMaster*> APawnCPP::getManors() {
    return TArray<ASMBuildingMaster*>();
}

TArray<ARegion*> APawnCPP::getMainTowns() {
    return TArray<ARegion*>();
}


TSoftObjectPtr<USkeletalMesh> APawnCPP::getLordVisitModeSkeletalMesh() {
    return NULL;
}

FString APawnCPP::getLordsName() {
    return TEXT("");
}

TArray<FLogEntry> APawnCPP::getLog() {
    return TArray<FLogEntry>();
}

bool APawnCPP::getLMBPressedB() {
    return false;
}

bool APawnCPP::getLetterCreatorMode() {
    return false;
}

int32 APawnCPP::getKingsFavourPlace() {
    return 0;
}

TArray<APawnCPP*> APawnCPP::getKingsFavourite() {
    return TArray<APawnCPP*>();
}

int32 APawnCPP::getKingsFavour_daysLeft() {
    return 0;
}

FItem APawnCPP::getItem(int32 ItemId) {
    return FItem{};
}

bool APawnCPP::getIsWinter() {
    return false;
}

bool APawnCPP::getIsUsingUI() {
    return false;
}

ASMBuildingMaster* APawnCPP::getHitBuilding() {
    return NULL;
}

void APawnCPP::getHiredMercenaryCompanies(TArray<int32>& squads, TArray<int32>& companyIDs, TArray<FMercenaryCompany>& companies, bool bIncludeFleeing) {
}

float APawnCPP::getGameSpeed() {
    return 0.0f;
}

bool APawnCPP::getFieldModeClosed() {
    return false;
}

bool APawnCPP::getFieldMode() {
    return false;
}

FVector APawnCPP::getFieldCenter() {
    return FVector{};
}

bool APawnCPP::getDummyCollision() {
    return false;
}

float APawnCPP::getDistSqToNearestPlannerStaticModule(const FVector& Pos, FVector& outModulePos) {
    return 0.0f;
}

int32 APawnCPP::getDaysUntilCompanyGetsPaid(int32 comapnyID) {
    return 0;
}

int32 APawnCPP::getdaysSinceLastExtortionAttempt(APawnCPP* byPawn) {
    return 0;
}

int32 APawnCPP::getDayOfTheYear() {
    return 0;
}

int32 APawnCPP::getDayOfTheMonthFromWeatherMaster() {
    return 0;
}

int32 APawnCPP::getCurrentYear() {
    return 0;
}

FSegment APawnCPP::getCurrentSquadLineProjection(int32 squadID) {
    return FSegment{};
}

ARegion* APawnCPP::getCurrentRegion() {
    return NULL;
}

TArray<FName> APawnCPP::getCurrentlyAvailableParagraphs(const TArray<FName>& currentLetter, APawnCPP* recipient, bool includeCantAfford) {
    return TArray<FName>();
}

int32 APawnCPP::getCompanyCostForPawn(const FMercenaryCompany& company) {
    return 0;
}

TArray<ASMBuildingMaster*> APawnCPP::getCommandedBuildings() {
    return TArray<ASMBuildingMaster*>();
}

ARegion* APawnCPP::getClosestRegion() const {
    return NULL;
}

bool APawnCPP::getCinematicMode() {
    return false;
}

FUnitStat APawnCPP::getAverageUnitStat(const FName& Temp) {
    return FUnitStat{};
}

FVector APawnCPP::getAverageFacingDirection(const TArray<int32>& squads, TArray<FVector>& outDirs) {
    return FVector{};
}

FUnitStat APawnCPP::getAverageEquipmentStat(const TArray<int32>& Items) {
    return FUnitStat{};
}

EAmbienceType APawnCPP::getAmbienceTypeOnPosition(const FVector& Pos) {
    return EAmbienceType::None;
}

TArray<FSquad> APawnCPP::getAllSquads() {
    return TArray<FSquad>();
}

TArray<FSquad> APawnCPP::getAllCommandedSquads() {
    return TArray<FSquad>();
}

TArray<ARegion*> APawnCPP::getAllCommandedRegions() {
    return TArray<ARegion*>();
}

TArray<ASMUnit*> APawnCPP::getAllCommandedMilitaryUnits() {
    return TArray<ASMUnit*>();
}

void APawnCPP::gameOver_Implementation(const int32& Type) {
}

void APawnCPP::formALineArmy(const TArray<int32>& squads, const FSegment& line, const FName& formationType, FSegment lastCommandedLineArmy) {
}

void APawnCPP::formALine(const TArray<ASMUnit*>& unitArr, const FVector& Start, const FVector& End, const uint8 floor) {
}

void APawnCPP::finishQuestByIndex(const int32& questID, const bool& Success, const bool& Remove) {
}

void APawnCPP::finishQuest(FQuest& Quest, bool Success, bool Remove) {
}

void APawnCPP::finishCinematicSequence() {
}

TArray<ASMUnit*> APawnCPP::findUnitsDoingAction(int32 ActionType, APawnCPP* ownerPawn) {
    return TArray<ASMUnit*>();
}

TArray<FVector> APawnCPP::findSharpPoints(const TArray<FVector>& Path, TArray<float>& props, const bool& parallelOnly) {
    return TArray<FVector>();
}

ARegion* APawnCPP::findRegionByName(const FString& regionName) {
    return NULL;
}

bool APawnCPP::findNearestWallSnapPoint(const FVector& Loc, float maxDistSq, FVector& OutLocation, float& outDistSq) {
    return false;
}

bool APawnCPP::findNearestRoadpoint(const ARegion* Region, const FVector& Position, FVector& OutNearestRoadpoint, bool bOnlyKingsRoad) const {
    return false;
}

FVector APawnCPP::findNearestMapEdge(const FVector& Position, float& outDistSq) {
    return FVector{};
}

float APawnCPP::findFormationDepth(const int32& squadID) {
    return 0.0f;
}

TArray<ARoad*> APawnCPP::findCommonRoads(const TArray<ARoad*>& roadsA, const TArray<ARoad*>& roadsB) {
    return TArray<ARoad*>();
}

FVector APawnCPP::findClosestPositionOnSegments(const FVector& Point, const TArray<FVector>& available) {
    return FVector{};
}

FVector APawnCPP::findClosestPosition(const FVector& Point, const TArray<FVector>& available) {
    return FVector{};
}

void APawnCPP::finalizeClaim(ARegion* Region, bool Remove) {
}

void APawnCPP::fieldRemovePoint() {
}

void APawnCPP::fieldAddPoint() {
}

float APawnCPP::fastSqrt(const float& N) {
    return 0.0f;
}

TArray<FVector> APawnCPP::extractSmoothSide(const TArray<FVector>& SmoothBorder, const FVector& cornerA, const FVector& cornerB) {
    return TArray<FVector>();
}

TArray<FVector> APawnCPP::extractIntersected(const TArray<FVector>& smoothSegment, const FSegment& intersectionA, const FSegment& intersectionB, const bool& intersectA, const bool& intersectB) {
    return TArray<FVector>();
}

void APawnCPP::eraseBuildingReferencesFromUI_Implementation(ASMBuildingMaster* building) {
}

bool APawnCPP::enactPolicy(ARegion* Region, const int32& slotNo, const int32& policyID) {
    return false;
}

void APawnCPP::drawSquadOverlays() {
}

void APawnCPP::drawBuildingOverlays() {
}

bool APawnCPP::doesPlacebuildingAffectDeerLair() {
    return false;
}

void APawnCPP::DMS_updateBattleIntensity() {
}

void APawnCPP::disbandSquad(int32 squadID) {
}

void APawnCPP::destroySelectedCastleBlueprint() {
}



void APawnCPP::deselectSquad(int32 squadID) {
}

void APawnCPP::deselectCastleBlueprint() {
}

void APawnCPP::deselectBuilding(ASMBuildingMaster* building) {
}

void APawnCPP::deselect_buildings() {
}

void APawnCPP::Deselect() {
}

void APawnCPP::declareWar(APawnCPP* targetPawn) {
}

void APawnCPP::declarePeace(APawnCPP* targetPawn) {
}

void APawnCPP::createDynamicUnitDecalMaterialIfNecessary() {
}

void APawnCPP::createAndPlayVictoryCinematic() {
}

void APawnCPP::createAndPlayGameOverCinematic() {
}

void APawnCPP::constructionComplete(ASMBuildingMaster* building) {
}

ARoad* APawnCPP::commitRoad() {
    return NULL;
}

ASMBuildingMaster* APawnCPP::commitField() {
    return NULL;
}

bool APawnCPP::collectsAnyTaxes() {
    return false;
}


void APawnCPP::closeAllTabs_Implementation() {
}

void APawnCPP::clearBufferedMovement() {
}

void APawnCPP::checkAndTriggerGameOver() {
}

void APawnCPP::ChangeTreasury(const int32 Amount) {
}

void APawnCPP::changeSilver(int32 amt) {
}

void APawnCPP::changeSelectedRegionUI_Implementation(ARegion* newSelectedRegion) {
}

void APawnCPP::changeSelectedBuildingPlatformLevel(int32 levelChange) {
}

void APawnCPP::changeSelectedBuildingBlueprintUpgradeLevel(int32 levelChange) {
}

void APawnCPP::changeRelationTags(APawnCPP* pawnB, const TArray<FName>& addTags, const TArray<FName>& removeTags) {
}

void APawnCPP::changeRelations(APawnCPP* pawnB, const float& change) {
}

void APawnCPP::changePlotOffset(int32 change) {
}

void APawnCPP::changeLetterRead(const FLetter& letterToChange, bool bLetterRead) {
}

void APawnCPP::changeKingsFavour(const int32& change) {
}

void APawnCPP::changeInfluence(const float& change) {
}

void APawnCPP::changeActiveRTSTool(ERTSTool newTool, AActor* toolActor, FName toolVariety) {
}

void APawnCPP::castlePlanningTools() {
}

bool APawnCPP::canClaimSomething() {
    return false;
}

bool APawnCPP::canChangeSelectedBuildingPlatformLevel(int32 levelChange) {
    return false;
}

bool APawnCPP::canChangeSelectedBuildingBlueprintUpgradeLevel(int32 levelChange) {
    return false;
}

bool APawnCPP::canAddNewMilitiaSquad(ARegion* inRegion) {
    return false;
}

void APawnCPP::cameraMovement(float deltaT) {
}

void APawnCPP::callCommitRoad_Implementation() {
}

int32 APawnCPP::calculateFieldWorkersNeeded(const TArray<FVector>& Points) {
    return 0;
}

void APawnCPP::beginNextQueuedCinematicShot() {
}



bool APawnCPP::anyArchersSelected() {
    return false;
}

void APawnCPP::animateDoorsCrude() {
}

bool APawnCPP::allArchersWithinRange(const int32& squadID, const int32& TargetId) {
    return false;
}

void APawnCPP::AffectAnimalLairs(ASMBuildingMaster* building) {
}

void APawnCPP::addUpgradeRequest(FUpgradeRequest newRequest) {
}

void APawnCPP::addTradeDeal(const FTradepoint& newDeal) {
}

void APawnCPP::addToOutbox(const FLetter& newLetter) {
}

void APawnCPP::addToInbox(const FLetter& newLetter) {
}

void APawnCPP::addTagRememberDay(const FName& newTag) {
}

void APawnCPP::addRetinueSquad(ARegion* Region) {
}

void APawnCPP::addResourceAddedLogs(const TArray<FGood>& newInventory, ASMBuildingMaster* building) {
}

void APawnCPP::addRemoveSquadRequest(int32 squadID) {
}

void APawnCPP::addMilitiaSquad(ARegion* Region, FName unitType) {
}

void APawnCPP::addLogIfNew(const FName& Tag, const FString& Text, const FString& descr, int32 opensMenu, const FVector& Pos, AActor* Actor) {
}

void APawnCPP::addLog(const FName& Tag, const FString& Text, const FString& descr, int32 opensMenu, const FVector& Pos, AActor* Actor) {
}

void APawnCPP::addExtensionChangeRequest(FUpgradeRequest newRequest) {
}

void APawnCPP::addCommitFieldRequest() {
}

void APawnCPP::addArtisanChangeRequest(FUpgradeRequest newRequest) {
}

void APawnCPP::acceptQuest(FQuest& Quest) {
}


