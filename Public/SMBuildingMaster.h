#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=SoftClassPath -FallbackName=SoftClassPath
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshActor -FallbackName=StaticMeshActor
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
#include "AnimalSpace.h"
#include "BuildingDataStruct.h"
#include "BuildingGloop.h"
#include "EAffinityType.h"
#include "EBuildingFunction.h"
#include "ECollapseModifier.h"
#include "ECropType.h"
#include "EItemSubcategory.h"
#include "EProductivityModifier.h"
#include "EReason.h"
#include "EResidentialRequirement.h"
#include "EUnitRole.h"
#include "EUpgradeType.h"
#include "EWallType.h"
#include "EYieldModifier.h"
#include "Extension.h"
#include "Good.h"
#include "Item.h"
#include "Order.h"
#include "Pair.h"
#include "RegionProviderInterface.h"
#include "RequirementCollection.h"
#include "RequirementsPerLevel.h"
#include "ResidentialRequirement.h"
#include "Segment.h"
#include "Segment2D.h"
#include "WorkerFamily.h"
#include "SMBuildingMaster.generated.h"

class AActor;
class APawnCPP;
class ARTSMultiEngineCPP;
class ARegion;
class ARoad;
class ASMBuilding;
class ASMBuildingMaster;
class ASMUnit;
class UDecalComponent;
class UExpertiseComponent;
class UMaintenanceComponent;
class UMaterialInterface;
class UParticleSystemComponent;
class UProductionTrackerComponent;
class UProficiencyComponent;
class USplineMeshComponent;
class UStaticMeshComponent;
class UTexture2D;
class UVARuntimeComponent;

UCLASS(Blueprintable)
class MANORLORDS_API ASMBuildingMaster : public AStaticMeshActor, public IRegionProviderInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARegion* Region;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APawnCPP* ownerPawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARTSMultiEngineCPP* masterPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMBuilding*> buildings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMBuilding*> Resources;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMaintenanceComponent* MaintenanceComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProficiencyComponent* ProficiencyComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExpertiseComponent* ExpertiseComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProductionTrackerComponent* ProductionTrackerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 typeBeforeChange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float fireAmt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool onFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* ps_fire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* PS_fireGrid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isBeingUpgraded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBuildingDataStruct Data;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBuildingFunction buildingFunction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGood> constructionGoods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> upgradesDone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGood> Inventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTabPinned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGood> resourceSurplusCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimalSpace animalSpaceCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> animalsOnPasture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 fieldWorkersNeeded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 fieldOperationMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 plannedHarvest_DaysLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 plannedHarvest_PredictedYield;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 yield;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool forceHarvest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRotateCrops;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECropType cropType2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECropType cropType3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDecalComponent* BoundsDecal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> roadDecals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDecalComponent* fieldDecal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* decalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* boundsDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* fieldDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* floorDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* roadDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* wellDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* roadPosDecalMatOnRoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> fieldPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool borderIsClockwise;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> fieldPointsTriangulated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> fieldBorderPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> finalBorder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool sleep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 buildPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString TownName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool workAreaLimited;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector workAreaCenter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float workAreaRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float workAreaRangeSq;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> oxen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 numActiveWorkerFamilies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 activeOxen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 maxOxen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> canMake;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FOrder> orders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBuildingGloop> ambiences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDrawPeopleConnections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDrawMarketConnections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTransform> additionalWorkPositions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool collidesWithRoads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDecalComponent* plagueDecal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> roadIntersectionPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExtension> extensions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 marketDaysLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 artisanJob;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> connectedRoadPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ARoad*> connectedRoadPointRoads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 secondaryPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool allowLabourers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool connectionNeedsVerifying;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float field_sowingPerc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float field_ploughingPerc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float field_growingPerc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float field_harvestingPerc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 field_numReadyToHarvest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 field_numUnplowed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 field_numSown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 numStoredGeneric;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 numStoredLarge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 numStoredPantry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 storageLimitGeneric;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 storageLimitLarge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 storageLimitPantry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> storageFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle vegetationEraserHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 vegetationEraseStage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> triangulatedBorderToErase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 waterSupply;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> customBuildingFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> moduleMasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bModuleMaster;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* moduleMasterPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* areaMasterBld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 sellingType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 targetSquadSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> recruits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARoad* snappedToRoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector roadPos;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isConnectedToTradeNetwork;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> walls;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 lv;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> Requirements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FRequirementCollection, int32> SatisfiedRequirementLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 supplyOverstocking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTransform> handcartSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool needsRefueling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool refueled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 refuelDay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 stockFuelFor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTransform> freeStallTransforms;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGood> distributedGoods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> blueprints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> blueprintGhosts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGood> equipmentDistributionReserve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 productionFocus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 mourningPeriod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* VAMP_AnimatedBuildingBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool VAMP_isPlaying;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> unitCache_transportTasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> unitCache_ownInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, int32> unitCache_transportTasks_distanceGroupCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float unitCache_transportTasks_lastTimeCached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> unitCache_farmingTasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> unitCache_craftingTasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> assignedFamilyIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> occupantFamilyIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* trainConnectionSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* trainConnectionTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARegion* trainConnectionRegion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 muleTrain_buyingType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 muleTrain_sellingType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool allowMarketStalls;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> shouldHighlightInventoryTabIDs;
    
    ASMBuildingMaster(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void verifyStorageProblems();
    
    UFUNCTION(BlueprintCallable)
    bool useUpgrade(int32 ID);
    
    UFUNCTION(BlueprintCallable)
    void updateRoadDecalMaterials();
    
    UFUNCTION(BlueprintCallable)
    void updateResourceSurplusCache();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updatePremadeFieldPoints();
    
    UFUNCTION(BlueprintCallable)
    void updateParticleSystemBasedOnWorkforce();
    
    UFUNCTION(BlueprintCallable)
    void updateNearbyWindmillEfficiency();
    
    UFUNCTION(BlueprintCallable)
    void updateMuleShoppingList();
    
    UFUNCTION(BlueprintCallable)
    void UpdateFieldCache(bool ploughing, bool sowing, bool growing, bool harvesting);
    
    UFUNCTION(BlueprintCallable)
    void updateFenceVisibilityBasedOnNeighbours(bool applyVisibilityChange);
    
    UFUNCTION(BlueprintCallable)
    bool unassignSingleWorkerFamily();
    
    UFUNCTION(BlueprintCallable)
    void triangulateExtensionArea(int32 slotID);
    
    UFUNCTION(BlueprintCallable)
    void takeOverOrAddMarketStalls();
    
    UFUNCTION(BlueprintCallable)
    void StartFire();
    
    UFUNCTION(BlueprintCallable)
    AActor* spawnVAMPAnimatedBuildingBP(FSoftClassPath BlueprintPath, const FTransform& WorldTransform);
    
    UFUNCTION(BlueprintCallable)
    void spawnRandomClutter(const FSegment& facade);
    
    UFUNCTION(BlueprintCallable)
    void spawnPlotDressing(int32 dressingType, const TArray<FVector>& sideA, const TArray<FVector>& sideB, const TArray<FVector>& sideC);
    
    UFUNCTION(BlueprintCallable)
    UStaticMeshComponent* spawnModuleMask();
    
    UFUNCTION(BlueprintCallable)
    void spawnManorServantsInside(int32 numServants);
    
    UFUNCTION(BlueprintCallable)
    void spawnFieldBorderShrubbery(const TArray<FVector>& borderPoints);
    
    UFUNCTION()
    void spawnBuildingsForUpgrade(const EUpgradeType upgradeType);
    
    UFUNCTION(BlueprintCallable)
    ASMUnit* spawnAnimal(EUnitRole animalRole);
    
    UFUNCTION(BlueprintCallable)
    bool shouldShowCraftingSpeed();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool shouldDisplayProductivityTracker();
    
    UFUNCTION(BlueprintCallable)
    void setWorkArea(const FVector& Center, const float& Range);
    
    UFUNCTION(BlueprintCallable)
    void SetupBuilding();
    
    UFUNCTION(BlueprintCallable)
    void setTabIsOpen(bool IsOpen);
    
    UFUNCTION(BlueprintCallable)
    void setSleep(bool newSleep);
    
    UFUNCTION(BlueprintCallable)
    void SetProtectResourceArea(bool InSetting);
    
    UFUNCTION(BlueprintCallable)
    void SetPriority(int32 NewPriority);
    
    UFUNCTION(BlueprintCallable)
    void setCustomBuildingFlag(int32 flagID, uint8 Value);
    
    UFUNCTION(BlueprintCallable)
    void setCropType(ECropType NewType);
    
    UFUNCTION(BlueprintCallable)
    void setConstructionPaused(bool paused);
    
    UFUNCTION(BlueprintCallable)
    void resetWorkArea();
    
    UFUNCTION(BlueprintCallable)
    bool removeActiveWorkerFamily();
    
    UFUNCTION(BlueprintCallable)
    void playVAMPAnimation(FName AnimationName);
    
    UFUNCTION(BlueprintCallable)
    void playChimneySmoke();
    
    UFUNCTION(BlueprintCallable)
    bool orderLivestock(int32 Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float muleTrain_getValueRatio();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isWinter();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isTavern();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isStorageTypeBuilding();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRubble() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isResidentialBuilding();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMineBuilding() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isMarketStall();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isMarketAssignable();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isManor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isHomelessTent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isFlammable();
    
    UFUNCTION(BlueprintCallable)
    bool isFamilyBusyAtWorkplace(const FWorkerFamily& WorkerFamily);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isDesiredMilitaryStockAtHomeReached();
    
    UFUNCTION(BlueprintCallable)
    void hireExtraRetinue();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasUpgrade(int32 upgradeID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool hasRoadSnapPoints(int32 bType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasReachedTransportLimits(const FVector& requestLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasOrder(const int32& orderType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasModuleOfType(int32 moduleType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasMaxActiveWorkerFamilies();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getYieldReadyToHarvest();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getWaterStorageCapacity();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UVARuntimeComponent* GetVARuntime();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FGood> GetUpgradeResourceCost(const int32 InUpgradeID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetType();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTriggeringRequirementLevel(const FRequirementCollection& InRequirementCollection) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<uint8> getTrigerringRequirements();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> getTradeableGoods();
    
    UFUNCTION(BlueprintCallable)
    FString getTownName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTotalProductivityValueInPercents() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getSurplusOfGood(int32 goodType, bool accountBringing, bool accountGrabbing, bool allowNegative);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FGood> getSurplusMilitaryEquipment();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EResidentialRequirement> GetSupplyCategoriesTriggeringApprovalLoss();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> GetSuppliedGoodTypesForRequirement(const FRequirementCollection& InRequirementCollection) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSummedYieldModifierValue() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FGood> getStoredMilitaryEquipment();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getStockOfDistributedGood(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getStallOwnerFamilyID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSown(int32& outNumSown);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getSleep();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSatisfiedRequirementLevel(const FRequirementCollection& InRequirementCollection) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRetinueHireTreasuryCost() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRequirementsPerLevel GetResidentialUpgradeRequirements() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRequirementsPerLevel GetResidentialTriggeringRequirementLevels() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FResidentialRequirement> GetResidentialRequirementsForSupplyCategory(EResidentialRequirement InSupplyCategory, const EItemSubcategory InMustHaveSubcategory) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FGood> getRequestedMilitaryEquipment();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARegion* getRegionOnLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRegionalWealthCostForUpgrade(const int32 InUpgradeID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARegion* GetRegion() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getReconstructedCastleArea(TArray<FVector>& reconstructedSmoothBorder, TArray<FVector>& reconstructedTriangulatedBorder);
    
    UFUNCTION(BlueprintCallable)
    float getRandomFloatInRangePredictable(float min, float max);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetProtectResourceArea() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> getProducingGoods(bool includeHidden) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> getProblems();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPriority();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getPriceOfGood(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APawnCPP* getOwnerPawn();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getOrderProgress(const int32& orderType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMUnit*> getOccupants();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FWorkerFamily> getOccupantFamiliesUI();
    
    UFUNCTION(BlueprintCallable)
    int32 getNumStoredLogs();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumResidingFamilies();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumReadyToHarvest();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumOrders(const int32& orderType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumMarketStallsOfType(int32 stallType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumMarketStalls();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumConnectedBuildingsOfFunction(EBuildingFunction Function);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D getNumBuilders() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumActiveWorkerFamilies();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<uint8> getNextLevelRequirments();
    
    UFUNCTION(BlueprintCallable)
    ASMBuilding* getNearestResource(const int32& resType, const FVector& Pos);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> getModuleTypes();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getModularGarrisonLimit();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EResidentialRequirement> GetMissingSupplyCategories() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getMaxWorkerFamilies() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getMaxSonsPerFamily();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getMaxResidingFamilies();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getMaxOxen();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getMaxOccupantsOfRole(EUnitRole roleToSearch);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getLowestImportPrice(int32 goodType, bool ignoreTradeRouteRequirements);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EUnitRole getLivestockWorkerRole();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getJobType();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FItem getItem(const int32& ItemId);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getIsTabOpened();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FGood> getInventory(bool includeModules);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FPair getImportPriceRange(int32 goodType, bool& OutMayIncludeTariff, bool bIgnoreTradeLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getHarvested();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> getGoodTypesForConstructionReserves();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> getGoodTypesConsumedForCurrentProduction(bool includeTransitionary, bool includeSpecialReserve);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<uint8> getFilledTrigerringRequirements();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getFieldWorkers();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getFieldReadyToSow();
    
    UFUNCTION(BlueprintCallable)
    int32 getExtensionHISM(const int32& ExtensionType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetExtensionAreaCostMultiplier() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString getDisplayNameKey() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FGood> getDesiredMilitaryEquipmentStockAtHome();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBuildingDataStruct getData();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getDailyPlantGrowth();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 getCustomBuildingFlag(int32 flagID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EResidentialRequirement> GetCurrentResidentialSupplyCategories() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> GetCurrentlyProducedGoodTypes() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getCurrentlyProducedGoodType();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getCurrentFoodSpoilageRate(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECropType getCropType();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> getCraftingConsumedGoodTypes(bool includeTransitionary, bool includeSpecialReserve);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMBuilding*> getControllableGates();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getConstructionStatus();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D getConstructionResourceSituation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getConstructionQueueID();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getConstructionProgress();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getConstructionPaused();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMBuildingMaster*> getConnectedSupplyBuildings();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<ECollapseModifier, float> GetCollapseModifiers() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCollapseChance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FGood> getCastleReconstructionCost(bool bOnlyBuildFirstBuilding);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getCastleLevelFromArea(float Area);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* getBuildingFunctionIcon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getBuildingArea();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMUnit*> getBoundRetinue();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getAvgPloughProgress(int32& outNumUnplowed);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getAvgCropProgress();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getAverageCropFertility(ECropType cropID);
    
    UFUNCTION(BlueprintCallable)
    TArray<FGood> getAverageConsumption();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getAvailableExportPrice(int32 goodType, bool bIgnoreTradeRestrictions);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ECropType> GetAvailableCropTypes();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMUnit*> getAttendingMerchants();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FGood> GetAssignedMilitaryEquipmentMinusAlreadyWearing();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FGood> getAssignedMilitaryEquipment();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FWorkerFamily> getAssignedFamiliesUI();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMUnit*> getAnimalsCurrentlyOnPasture();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMUnit*> getAnimals();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMUnit*> getAllWorkers();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> getAllPossibleUpgrades(bool bIncludeExtensions) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSet<EAffinityType> GetAffinities() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<EYieldModifier, int32> GetActiveYieldModifiersWithValues() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<EProductivityModifier, int32> GetActiveProductivityModifiersWithValues() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARegion* findRegionByName(const FString& regionName);
    
    UFUNCTION(BlueprintCallable)
    void findRegionAndOwner(ARegion* SetRegion);
    
    UFUNCTION(BlueprintCallable)
    void eraseVegetationSlow();
    
    UFUNCTION(BlueprintCallable)
    void eraseVegetation(const TArray<FVector>& triangulatedBorderToCheck);
    
    UFUNCTION(BlueprintCallable)
    void eraseCrops(bool erasePlowing);
    
    UFUNCTION(BlueprintCallable)
    void drawPeopleArcs();
    
    UFUNCTION(BlueprintCallable)
    void drawMarketArcs();
    
    UFUNCTION(BlueprintCallable)
    bool doesWallSegmentOverlap(const FSegment2D& wallSegment);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool doesFlipFlopProduction();
    
    UFUNCTION(BlueprintCallable)
    bool doesFenceOverlapAnyUnhiddenNeighbourFence(USplineMeshComponent* fenceMesh);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool doesDistributeRequirementGoods();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool doesCastleModuleNeedReconstruction(AActor* Actor, int32 newModuleBuildingId, EWallType wallType);
    
    UFUNCTION(BlueprintCallable)
    bool doesBuildingConsumeResource(int32 Type, bool includingForConstruction, bool includeWeaponReservation, bool includeTrade);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool displayStorageUI();
    
    UFUNCTION(BlueprintCallable)
    void demolish(bool refund);
    
    UFUNCTION(BlueprintCallable)
    void convertBlueprintsToBuildings(bool bOnlyBuildFirstBuilding);
    
    UFUNCTION(BlueprintCallable)
    void consumeGoodNoCheck(int32 goodType);
    
    UFUNCTION(BlueprintCallable)
    void collapseBuilding();
    
    UFUNCTION(BlueprintCallable)
    void changeTrainConnectionRegion(int32 uniqueRegionID);
    
    UFUNCTION(BlueprintCallable)
    void ChangeProductionFocus(int32 NewProductionFocus);
    
    UFUNCTION(BlueprintCallable)
    void changeMuleTrain_sellingType(int32 NewType);
    
    UFUNCTION(BlueprintCallable)
    void changeMuleTrain_buyingType(int32 NewType);
    
    UFUNCTION(BlueprintCallable)
    void ChangeExtension(int32 Slot, int32 NewType);
    
    UFUNCTION(BlueprintCallable)
    void changeArtisanType(int32 ExtensionType);
    
    UFUNCTION(BlueprintCallable)
    void changeActiveLivestockWorkers(int32 amt);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool canUpgrade(int32 ID, TArray<FName>& resonsCant);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool canSetWorkArea();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanSelectCropType();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool canMakeAnything();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool canHireRetinue();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool canConstructCastle(TArray<EReason>& outReasons);
    
    UFUNCTION(BlueprintCallable)
    void cancelOrder(const int32& orderType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool canBuildingTypeSetupMarketStalls();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool canBeDemolished();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool canAffordCastleReconstruction();
    
    UFUNCTION(BlueprintCallable)
    void callMarket();
    
    UFUNCTION(BlueprintCallable)
    bool buildingIsExtension(ASMBuilding* building);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool areExtensionUpgradesAvailable();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool anythingReadyToHarvest();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AllResidentialRequirementsSatisfied() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool allDirtFlattened();
    
    UFUNCTION(BlueprintCallable)
    void addToInventory(const FGood& Good);
    
    UFUNCTION(BlueprintCallable)
    bool addActiveWorkerFamily();
    
    UFUNCTION(BlueprintCallable)
    void abandonAllMarketStalls();
    

    // Fix for true pure virtual functions not being implemented
};

