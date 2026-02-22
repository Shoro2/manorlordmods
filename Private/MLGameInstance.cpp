#include "MLGameInstance.h"

UMLGameInstance::UMLGameInstance() {
    this->PlatformManager = NULL;
    this->MetaMetric = NULL;
    this->NetMan = NULL;
    this->InputIconManager = NULL;
    this->PixelFed = NULL;
    this->moveDecalMesh = NULL;
    this->playerPortrait = NULL;
    this->MLplayerPawnBP = NULL;
    this->DT_Quirks = NULL;
    this->DT_GameSetupPresets = NULL;
    this->DT_CoatOfArmsDatabase = NULL;
    this->coatOfArmsLinearFixerMaterial = NULL;
    this->coatOfArmsLinearFixerDynamic = NULL;
    this->simpleCoatGeneratorMaterial = NULL;
    this->aggressive_AI = false;
    this->AI_behaviour = 0;
    this->currentGameVictoryStatus = EVictoryStatus::Ongoing;
    this->alwaysShowResourceIcons = true;
    this->bEnableEdgeScrolling = true;
    this->GrassDensity = 1.00f;
    this->grassRenderingDistance = 1.00f;
    this->triggerQuests = false;
    this->autoIdleJobs = true;
    this->noticeSquadSetting = ENoticeSquadSetting::SlowGame;
    this->zoomToCameraAmt = 0.00f;
    this->graphicsPresetAsset = NULL;
    this->startWithCart = false;
}


void UMLGameInstance::updateResourceImmediate(UTextureRenderTarget2D* RenderTarget, bool bClearRenderTarget) {
}


void UMLGameInstance::updateBorderFrameDataRenderThread(UUserWidget* Widget, UMaterialInstanceDynamic* borderMaterialDynamic) {
}

void UMLGameInstance::updateAchievementData(FName AchievementName, int32 Score) {
}

void UMLGameInstance::unassignFromRegion(const FVillageSpawnerData& InSpawner, const int32 pawnIndex) {
}

void UMLGameInstance::unassignedStartLocation(const FVillageSpawnerData& InSpawner, const int32 pawnIndex) {
}

void UMLGameInstance::ToggleAdversary(const bool InAdversaryEnabled) {
}

void UMLGameInstance::sortIndexMapByDate(TMap<int32, FDateTime>& mapToSort) {
}

void UMLGameInstance::SetZoomToCursorAmount(float zoomAmount) {
}


void UMLGameInstance::SetUseVolumetricClouds(bool useVolumetricClouds) {
}


void UMLGameInstance::SetUseTutorials(bool useTutorials) {
}

void UMLGameInstance::setUIScale(float NewScale) {
}

void UMLGameInstance::setStartLocation(const FVillageSpawnerData& InSpawner, const int32 pawnIndex) {
}

void UMLGameInstance::setRandomStartLocations(const FMapDataRow& MapData) {
}

void UMLGameInstance::SetNumAILords(const int32 InNum) {
}

void UMLGameInstance::SetNoticeEnemyBehaviour(int32 noticeEnemyBehaviour) {
}

bool UMLGameInstance::SetMouseRelativePosition(float xRatio, float yRatio) {
    return false;
}

void UMLGameInstance::SetMouseLock(int32 IsLocked) {
}

void UMLGameInstance::setLordsArms(int32 pawnIndex, UTextureRenderTarget2D* armsRenderTarget, FCoatOfArmsData armsData) {
}

void UMLGameInstance::SetGrassRenderDistance(float newGrassRenderingDistance) {
}

void UMLGameInstance::SetGrassDensity(float newGrassDensity) {
}

void UMLGameInstance::SetEdgeScrolling(bool useEdgeScrolling) {
}


void UMLGameInstance::SetDayNightCycle(bool doCycle) {
}

void UMLGameInstance::setCurrentGameSetup(const FGameSetupPreset& setupPreset, EGameDifficulty chosenDifficulty) {
}


void UMLGameInstance::SetAutosavePeriod(float autosavePeriod) {
}

void UMLGameInstance::SetAlwaysShowResourceIcons(bool newAlwaysShowResources) {
}

bool UMLGameInstance::saveCoatOfArmsImageByName(UObject* WorldContextObject, UTextureRenderTarget2D* coatImage, const FString& Filename) {
    return false;
}

bool UMLGameInstance::saveCoatOfArmsImage(UObject* WorldContextObject, int32 armsIndex, const FString& saveName) {
    return false;
}

void UMLGameInstance::ReportSettingsChanged() {
}


void UMLGameInstance::preallocateSpawnLocations() {
}

bool UMLGameInstance::MoveMouseToStartDefault() {
    return false;
}

bool UMLGameInstance::loadCoatOfArmsImage(int32 Index, const FString& saveName) {
    return false;
}

TArray<FName> UMLGameInstance::ListSupportedLanguages() {
    return TArray<FName>();
}

bool UMLGameInstance::isRegionEmpty(const FRegionData& InRegionData, TArray<FVillageSpawnerData>& OutVillagesInRegion) const {
    return false;
}

bool UMLGameInstance::isCurrentGameSetup(const FGameSetupPreset& setupPreset, EGameDifficulty& outDifficultyThatMatches) {
    return false;
}

bool UMLGameInstance::isCommonResolution(FVector2D Resolution) {
    return false;
}

UTexture2D* UMLGameInstance::ImportSaveThumbnail(UObject* WorldContextObject, const FString& SaveGameName) {
    return NULL;
}

float UMLGameInstance::getUIScale() {
    return 0.0f;
}

FText UMLGameInstance::getTranslatedTextFromDataTable(FName textKey, UDataTable* DataTable) {
    return FText::GetEmpty();
}

TArray<FGood> UMLGameInstance::getStartingSupplies(uint8 Level, int32& outCost) {
    return TArray<FGood>();
}

float UMLGameInstance::getSpoilageRateFromGameSetting() {
    return 0.0f;
}

void UMLGameInstance::getSavedAutoSettingFloatValue_Implementation(const FName& SettingName, float& OutValue) {
}

void UMLGameInstance::getSavedAutoSettingBoolValue_Implementation(const FName& SettingName, bool& OutValue) {
}

FString UMLGameInstance::getRandomName(bool female, const TArray<FString>& namesToAvoid) {
    return TEXT("");
}

int32 UMLGameInstance::GetPreset(bool& OutPresetFound) const {
    return 0;
}

UTexture2D* UMLGameInstance::getPortraitByName(FName portraitName) {
    return NULL;
}

UPixelFed* UMLGameInstance::getPixelFed() const {
    return NULL;
}

int32 UMLGameInstance::GetPawnIndexForStartLocation(const FTransform& InTransform) const {
    return 0;
}

int32 UMLGameInstance::getOwningPawnIndex(const FRegionData& InRegionData) const {
    return 0;
}

UDataTable* UMLGameInstance::GetNamedTable(FName tableName) {
    return NULL;
}

UTextureRenderTarget2D* UMLGameInstance::getLordsArms(int32 pawnIndex) {
    return NULL;
}

FString UMLGameInstance::GetLordNameByIndex(const int32 InPawnIndex) const {
    return TEXT("");
}

FString UMLGameInstance::GetDisplayAppVersion() {
    return TEXT("");
}

FString UMLGameInstance::getDefaultOSLanguage() {
    return TEXT("");
}

FString UMLGameInstance::GetAppVersion() {
    return TEXT("");
}

UTextureRenderTarget2D* UMLGameInstance::generateSimpleCoatOfArms(int32 pawnIndex, const FCoatOfArmsData& coatData) {
    return NULL;
}

void UMLGameInstance::ExportSaveThumbnailRT(UObject* WorldContextObject, UTextureRenderTarget2D* TextureRenderTarget, const FString& SaveGameName) {
}

void UMLGameInstance::DeleteSaveThumbnail(UObject* WorldContextObject, const FString& SaveGameName) {
}

void UMLGameInstance::ApplyPreset(const uint8 InPresetVal) {
}

void UMLGameInstance::AILordCountChanged() const {
}


