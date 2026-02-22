#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Color -FallbackName=Color
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=DateTime -FallbackName=DateTime
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=GameInstance -FallbackName=GameInstance
#include "AudioSliders.h"
#include "CoatOfArmsData.h"
#include "EGameDifficulty.h"
#include "ENoticeSquadSetting.h"
#include "EVictoryStatus.h"
#include "GameSetupMapData.h"
#include "GameSetupPreset.h"
#include "Good.h"
#include "MapDataRow.h"
#include "OnAILordCountChangedDelegate.h"
#include "OnChangeReportedDelegate.h"
#include "OnStartLocationChangedDelegate.h"
#include "PlayerStartingSetup.h"
#include "Portrait.h"
#include "RTSSettings.h"
#include "RegionData.h"
#include "Templates/SubclassOf.h"
#include "VillageSpawnerData.h"
#include "MLGameInstance.generated.h"

class APawnCPP;
class UDataTable;
class UGraphicsSettingsPresets;
class UInputIconManager;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMetaMetric;
class UNetMan;
class UObject;
class UPixelFed;
class UPlatformManager;
class UStaticMesh;
class UTexture2D;
class UTextureRenderTarget2D;
class UUserWidget;

UCLASS(Blueprintable, NonTransient)
class MANORLORDS_API UMLGameInstance : public UGameInstance {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPlatformManager* PlatformManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMetaMetric* MetaMetric;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNetMan* NetMan;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputIconManager* InputIconManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPixelFed* PixelFed;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* moveDecalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FColor> allPlayerColors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPortrait> lordPortraits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPortrait> banditPortraits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* playerPortrait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString playerLordsName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> lordNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<APawnCPP> MLplayerPawnBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPlayerStartingSetup> startingSetup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_Quirks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UDataTable*> namedTables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_GameSetupPresets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTextureRenderTarget2D*> lordArms;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCoatOfArmsData> CoatOfArmsData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_CoatOfArmsDatabase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* coatOfArmsLinearFixerMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* coatOfArmsLinearFixerDynamic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* simpleCoatGeneratorMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString savefileToLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName scenario;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool aggressive_AI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 AI_behaviour;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EVictoryStatus currentGameVictoryStatus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameSetupPreset gameSetup;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnStartLocationChanged onStartLocationChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAILordCountChanged OnAILordCountChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGameSetupMapData> PerMapSpawnData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAudioSliders AudioSliders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRTSSettings Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool alwaysShowResourceIcons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableEdgeScrolling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GrassDensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float grassRenderingDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool triggerQuests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool autoIdleJobs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENoticeSquadSetting noticeSquadSetting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float zoomToCameraAmt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGraphicsSettingsPresets* graphicsPresetAsset;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnChangeReported OnChangeReported;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool startWithCart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Version;
    
    UMLGameInstance();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool WriteSettingsToDisk();
    
    UFUNCTION(BlueprintCallable)
    void updateResourceImmediate(UTextureRenderTarget2D* RenderTarget, bool bClearRenderTarget);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool UpdateMouseFocusAndLock();
    
    UFUNCTION(BlueprintCallable)
    void updateBorderFrameDataRenderThread(UUserWidget* Widget, UMaterialInstanceDynamic* borderMaterialDynamic);
    
    UFUNCTION(BlueprintCallable)
    void updateAchievementData(FName AchievementName, int32 Score);
    
    UFUNCTION(BlueprintCallable)
    void unassignFromRegion(const FVillageSpawnerData& InSpawner, const int32 pawnIndex);
    
    UFUNCTION(BlueprintCallable)
    void unassignedStartLocation(const FVillageSpawnerData& InSpawner, const int32 pawnIndex);
    
    UFUNCTION(BlueprintCallable)
    void ToggleAdversary(const bool InAdversaryEnabled);
    
    UFUNCTION(BlueprintCallable)
    void sortIndexMapByDate(UPARAM(Ref) TMap<int32, FDateTime>& mapToSort);
    
    UFUNCTION(BlueprintCallable)
    void SetZoomToCursorAmount(float zoomAmount);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool SetUseVolumetricCloudsOnPawn(bool newUseVolClouds);
    
    UFUNCTION(BlueprintCallable)
    void SetUseVolumetricClouds(bool useVolumetricClouds);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool SetUseTutorialsOnPawn(bool newUseTutorials);
    
    UFUNCTION(BlueprintCallable)
    void SetUseTutorials(bool useTutorials);
    
    UFUNCTION(BlueprintCallable)
    void setUIScale(float NewScale);
    
    UFUNCTION(BlueprintCallable)
    void setStartLocation(const FVillageSpawnerData& InSpawner, const int32 pawnIndex);
    
    UFUNCTION(BlueprintCallable)
    void setRandomStartLocations(const FMapDataRow& MapData);
    
    UFUNCTION(BlueprintCallable)
    void SetNumAILords(const int32 InNum);
    
    UFUNCTION(BlueprintCallable)
    void SetNoticeEnemyBehaviour(int32 noticeEnemyBehaviour);
    
    UFUNCTION(BlueprintCallable)
    bool SetMouseRelativePosition(float xRatio, float yRatio);
    
    UFUNCTION(BlueprintCallable)
    void SetMouseLock(int32 IsLocked);
    
    UFUNCTION(BlueprintCallable)
    void setLordsArms(int32 pawnIndex, UTextureRenderTarget2D* armsRenderTarget, FCoatOfArmsData armsData);
    
    UFUNCTION(BlueprintCallable)
    void SetGrassRenderDistance(float newGrassRenderingDistance);
    
    UFUNCTION(BlueprintCallable)
    void SetGrassDensity(float newGrassDensity);
    
    UFUNCTION(BlueprintCallable)
    void SetEdgeScrolling(bool useEdgeScrolling);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool setDayNightCycleLightSetting(bool NewValue);
    
    UFUNCTION(BlueprintCallable)
    void SetDayNightCycle(bool doCycle);
    
    UFUNCTION(BlueprintCallable)
    void setCurrentGameSetup(const FGameSetupPreset& setupPreset, EGameDifficulty chosenDifficulty);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool SetAutosavePeriodOnPawn(float newAutosavePeriod);
    
    UFUNCTION(BlueprintCallable)
    void SetAutosavePeriod(float autosavePeriod);
    
    UFUNCTION(BlueprintCallable)
    void SetAlwaysShowResourceIcons(bool newAlwaysShowResources);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    bool saveCoatOfArmsImageByName(UObject* WorldContextObject, UTextureRenderTarget2D* coatImage, const FString& Filename);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    bool saveCoatOfArmsImage(UObject* WorldContextObject, int32 armsIndex, const FString& saveName);
    
    UFUNCTION(BlueprintCallable)
    void ReportSettingsChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool ReadSettingsFromDisk();
    
    UFUNCTION(BlueprintCallable)
    void preallocateSpawnLocations();
    
    UFUNCTION(BlueprintCallable)
    bool MoveMouseToStartDefault();
    
    UFUNCTION(BlueprintCallable)
    bool loadCoatOfArmsImage(int32 Index, const FString& saveName);
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> ListSupportedLanguages();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isRegionEmpty(const FRegionData& InRegionData, TArray<FVillageSpawnerData>& OutVillagesInRegion) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isCurrentGameSetup(const FGameSetupPreset& setupPreset, EGameDifficulty& outDifficultyThatMatches);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isCommonResolution(FVector2D Resolution);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UTexture2D* ImportSaveThumbnail(UObject* WorldContextObject, const FString& SaveGameName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getUIScale();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText getTranslatedTextFromDataTable(FName textKey, UDataTable* DataTable);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FGood> getStartingSupplies(uint8 Level, int32& outCost);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSpoilageRateFromGameSetting();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void getSavedAutoSettingFloatValue(const FName& SettingName, float& OutValue);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void getSavedAutoSettingBoolValue(const FName& SettingName, bool& OutValue);
    
    UFUNCTION(BlueprintCallable)
    static FString getRandomName(bool female, const TArray<FString>& namesToAvoid);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPreset(bool& OutPresetFound) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* getPortraitByName(FName portraitName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPixelFed* getPixelFed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPawnIndexForStartLocation(const FTransform& InTransform) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getOwningPawnIndex(const FRegionData& InRegionData) const;
    
    UFUNCTION(BlueprintCallable)
    UDataTable* GetNamedTable(FName tableName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTextureRenderTarget2D* getLordsArms(int32 pawnIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetLordNameByIndex(const int32 InPawnIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetDisplayAppVersion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString getDefaultOSLanguage();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetAppVersion();
    
    UFUNCTION(BlueprintCallable)
    UTextureRenderTarget2D* generateSimpleCoatOfArms(int32 pawnIndex, const FCoatOfArmsData& coatData);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ExportSaveThumbnailRT(UObject* WorldContextObject, UTextureRenderTarget2D* TextureRenderTarget, const FString& SaveGameName);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DeleteSaveThumbnail(UObject* WorldContextObject, const FString& SaveGameName);
    
    UFUNCTION(BlueprintCallable)
    void ApplyPreset(const uint8 InPresetVal);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void AILordCountChanged() const;
    
};

