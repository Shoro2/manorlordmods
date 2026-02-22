#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Color -FallbackName=Color
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=VisualLoggerDebugSnapshotInterface -FallbackName=VisualLoggerDebugSnapshotInterface
#include "EAnimMode.h"
#include "EAttackMethod.h"
#include "EBehaviourStance.h"
#include "EEquipmentSlot.h"
#include "ELocomotionStance.h"
#include "EPushStance.h"
#include "EUnitRole.h"
#include "EUnitTrait.h"
#include "Equipment.h"
#include "Good.h"
#include "PathPoint.h"
#include "PotentialFactor.h"
#include "RegionProviderInterface.h"
#include "Segment2D.h"
#include "Task.h"
#include "UnitDataStruct.h"
#include "UnitTemplate.h"
#include "SMUnit.generated.h"

class APawnCPP;
class ARTSMultiEngineCPP;
class ARegion;
class AResource;
class ARoad;
class ASMBuildingMaster;
class ASMUnit;
class UDataTable;
class UParticleSystem;
class USpatialEntityComponent;
class UStaticMeshComponent;
class UVAISMControllerAbstract;

UCLASS(Blueprintable)
class ASMUnit : public AActor, public IRegionProviderInterface, public IVisualLoggerDebugSnapshotInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool dead;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARTSMultiEngineCPP* masterPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* animalAssignedTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* Home;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 workerFamilyID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float potential;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPotentialFactor> potentialFactors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBehaviourStance behaviourStance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPushStance pushStance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPushStance pushStanceBeforeMoraleDrop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 checkpoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> checkpoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> temporalCheckpoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LPathSpeedfactorCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARoad* onRoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 locomotionAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool locomotionIsIdle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 currAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 targetAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector realPos;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Speed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float realSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool closeToFinal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float speedFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float climbingSpeedFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float squadLowestClimbingSpeedFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 floor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool snappedToTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float leftoverSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float velo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isOnBuilding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector interpolatedMoveVector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector obstructionV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float pathCheckTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator realRot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 obstructed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool avoidedObstruction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPathPoint> Path;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PathPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 spatialGridIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector dir;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGood> Inventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Action;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName taskLabelOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTask> Tasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 wasIdle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 waitingOnTransportLimitsCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool performedHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float baseAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float baseDefence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float baseRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float baseBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float baseCharge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float att;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float rangedAtt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Def;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Range;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float rangeSq;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float shootingRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float shootingRangeSq;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float bLock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float charge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float chargeStop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float armorPierce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float shieldwallBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float morale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float stamina;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool defenseBroken;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float combatExperience;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHoldingLine;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFortified;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFireAtWill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHoldFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEquipment Equipment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEquipment equipmentOnRally;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMUnit* ClosestEnemyUnit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool battleStance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool closeProximity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool fightingStance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool inChargeDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELocomotionStance locomotionStance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool force1hAttacks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAttackMethod attackMethod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 repetitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 targetRepetitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool sprintMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float moveToEnemyRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool cosmeticEquipmentOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 queuedItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 animRandomVariation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 lastPlayedVariation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EEquipmentSlot, uint8> equipmentMeshVariations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EEquipmentSlot, uint8> equipmentTextureVariations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EEquipmentSlot, FVector> equipmentColorSchemeUVs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float shieldSymbolIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUnitRole currentUnitRole;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUnitRole assignedUnitRole;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float pregnancy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Age;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float meleeTraining;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float archeryTraining;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName unitTemp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 surrounded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 exposed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMUnit* lastFiringTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool spreadOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool friendlyFirePossible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool friendlyFireAllowed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool tacticalRetreat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector retreatPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float engagementPercentage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DrawTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARegion* currentRegion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector2D> targetMemory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* chosenPasture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 mountAnimFlavour;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool foundCommonLpath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EUnitTrait> Traits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool unitsPassingThrough;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool unitsPassingSameDir;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> possibleTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float moveToFaceDot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float moveRightDot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector movingRightV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool forceFacingForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool movingSideways;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool strafeRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool strafeLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool walkForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 closeEnemyUpdateLag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float nearThresholdSq;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float animSpeedFac;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool squadAnyFriendlyFirePossible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName currentAnimset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimMode animMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 instanceUpdateLag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector lastInstacePosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector prevToLastInstacePosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> roadPathPointIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* dropsTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARegion* lastTradedWith;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARegion* lastSoldTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float lastVeloUpdTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool raiding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 itemsLooted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 regionUpdateTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 lastTrumpetTargetSquadID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 livestockRunawayTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector laggingBottomPos;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isBeingRallied;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform rallyingTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 currAnimAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> unitDebugLog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 voiceID;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UVAISMControllerAbstract>> VAMPControllers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpatialEntityComponent* SpatialEntityComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* currentAnimsetDT;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float currentAnimSpd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float currentAnimSpdDefault;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float lastTransitionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float previouslySetTransitionDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FinalYawCorrection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> quirks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 UniqueID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 assignedSquadID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGood> assignedMilitaryEquipment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> staticMeshGoods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTransform> staticMeshGoods_relativeTransforms;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMUnit* mountActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isMount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGood> shoppingList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FString> customUnitData;
    
    ASMUnit(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void writeUnitDebugLog(const FString& newLogEntry);
    
    UFUNCTION(BlueprintCallable)
    bool useSkill(int32 skill);
    
    UFUNCTION(BlueprintCallable)
    void updateTraits();
    
    UFUNCTION(BlueprintCallable)
    void updateSquadAnyFriendlyFirePossible();
    
    UFUNCTION(BlueprintCallable)
    void updateSquadAI();
    
    UFUNCTION(BlueprintCallable)
    void updateSpreadDist();
    
    UFUNCTION(BlueprintCallable)
    ASMUnit* updateNearestLazyFriend();
    
    UFUNCTION(BlueprintCallable)
    void updateDecalVisibility();
    
    UFUNCTION(BlueprintCallable)
    void updateCurrentRegion(bool squadCenter);
    
    UFUNCTION(BlueprintCallable)
    void UnhideVAMPSlot(EEquipmentSlot Slot);
    
    UFUNCTION(BlueprintCallable)
    bool unequip(EEquipmentSlot Slot);
    
    UFUNCTION(BlueprintCallable)
    void turnToSoldierJoinSquad(int32 squadToJoin);
    
    UFUNCTION(BlueprintCallable)
    void turnToBandit();
    
    UFUNCTION(BlueprintCallable)
    void triggerSquadRetreat();
    
    UFUNCTION(BlueprintCallable)
    void triggerEnemyCheer(ARegion* Region);
    
    UFUNCTION(BlueprintCallable)
    void step();
    
    UFUNCTION(BlueprintCallable)
    void squadRetreatAndReformIfClose();
    
    UFUNCTION(BlueprintCallable)
    bool squadOnPosition(const float& Percentage, bool excludeStragglers);
    
    UFUNCTION(BlueprintCallable)
    bool squadIsTargetingThis(ASMUnit* unit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool squadFinishedRecruiting();
    
    UFUNCTION(BlueprintCallable)
    void spawnStaticGoodVisualization();
    
    UFUNCTION(BlueprintCallable)
    void SetVAMPVariationsToEquipment();
    
    UFUNCTION(BlueprintCallable)
    void setVAMPControllerCustomData(EEquipmentSlot equimentSlot);
    
    UFUNCTION(BlueprintCallable)
    void setVAMPColorSchemeUVsForSlot(EEquipmentSlot Slot, FVector newColorScheme);
    
    UFUNCTION(BlueprintCallable)
    void setTask(const FTask& newTask);
    
    UFUNCTION(BlueprintCallable)
    void setSprintModeWholeSquad(bool NewMode);
    
    UFUNCTION(BlueprintCallable)
    bool setSpreadOut_WholeSquad(const bool& newSetting);
    
    UFUNCTION(BlueprintCallable)
    void setRetreatPositionWholeSquad();
    
    UFUNCTION(BlueprintCallable)
    void setRaidingWholeSquad(bool newSetting);
    
    UFUNCTION(BlueprintCallable)
    void setPushStance(const EPushStance& newStance, bool byMorale, bool playVoiceline);
    
    UFUNCTION(BlueprintCallable)
    void setFriendlyFireAllowedWholeSquad(const bool& newSetting);
    
    UFUNCTION(BlueprintCallable)
    void setFortified(bool newFortified);
    
    UFUNCTION(BlueprintCallable)
    void setCrossbowHolsterStateIfNeeded(bool holstered);
    
    UFUNCTION(BlueprintCallable)
    void setBehaviourStance(const EBehaviourStance& newStance, bool playVoiceline);
    
    UFUNCTION(BlueprintCallable)
    void removeFromSquad();
    
    UFUNCTION(BlueprintCallable)
    void removeFromFamilyIfHasOne(bool deleteEmptyFamily);
    
    UFUNCTION(BlueprintCallable)
    void playVfx(UParticleSystem* ParticleSystem, FName SocketName, FTransform Offset);
    
    UFUNCTION(BlueprintCallable)
    void playSoundCueFromDatabaseIfClose(FName cueName);
    
    UFUNCTION(BlueprintCallable)
    void playHitFx();
    
    UFUNCTION(BlueprintCallable)
    void playGruntFxSometimesIfClose();
    
    UFUNCTION(BlueprintCallable)
    void playGruntFxSometimes();
    
    UFUNCTION(BlueprintCallable)
    void pickRandomName();
    
    UFUNCTION(BlueprintCallable)
    bool pickNewShootingTarget();
    
    UFUNCTION(BlueprintCallable)
    bool pickAttackAction(ASMUnit* targetUnit, bool backstab);
    
    UFUNCTION(BlueprintCallable)
    void performHit();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ownsArtisanWorkshop() const;
    
    UFUNCTION(BlueprintCallable)
    bool murderVillagersNear(const FVector& Position, float maxDistSq);
    
    UFUNCTION(BlueprintCallable)
    void just_die();
    
    UFUNCTION(BlueprintCallable)
    bool isWagonEquipped();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isVAMPControllerVisibile(EEquipmentSlot equimentSlot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isUnitWithinMapBounds();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isSquadFleeing();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isSquadEngaged();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSpatiallyVisible();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isSoldier() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isSkillAvailable(int32 skillID, TArray<FName>& outReasonsNot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isSkillActive(int32 skillID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isRangedUnit();
    
    UFUNCTION(BlueprintCallable)
    bool isPloughEquipped();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isHumanCivilian(bool includeRetainers);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isFamilyInjured();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isFamilyHead();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isFamilyDiseased();
    
    UFUNCTION(BlueprintCallable)
    bool isEquipped(int32 ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isDisbanded();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool inEditor();
    
    UFUNCTION(BlueprintCallable)
    void HideVAMPSlot(EEquipmentSlot Slot);
    
    UFUNCTION(BlueprintCallable)
    void hideVAMPControllers();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasValidFamily() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasNoFamilyMembers();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASMBuildingMaster* getWorkplace() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getVoiceID();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 getVAMPTextureVariationIDForSlot(EEquipmentSlot Slot) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 getVAMPMeshVariationIDForSlot(EEquipmentSlot Slot) const;
    
    UFUNCTION(BlueprintCallable)
    UVAISMControllerAbstract* getVAMPController(EEquipmentSlot Slot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getVAMPColorSchemeUVsForSlot(EEquipmentSlot Slot) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getUnitSquadTemplateName();
    
    UFUNCTION(BlueprintCallable)
    TArray<ASMUnit*> getUnitsBlockingLine(const FSegment2D& line, const TArray<ASMUnit*> unitsToCheck, const int32& skipID, APawnCPP* onlyOwner);
    
    UFUNCTION(BlueprintCallable)
    int32 getTradeRouteMerchantsTradingGoodType();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getTaskLabel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getTargetPos();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> getStatus();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMUnit*> GetSquadUnits();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EUnitTrait> getSquadTraits();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASMUnit* getSquadLeader();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getSquadFormationSpread();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getSquadCenter();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> getSquadAudioTags();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getJobType() const;
    
    UFUNCTION(BlueprintCallable)
    FName getItemVariationName(int32 goodID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EEquipmentSlot getItemEquipmentSlot(int32 ItemId, bool useCarryingVariationIfPossible);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetInterpolatedLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASMBuildingMaster* getHome();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASMBuildingMaster* getFamilyStall();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getFamilyLevel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetEquippedID(EEquipmentSlot Slot);
    
    UFUNCTION(BlueprintCallable)
    TArray<ASMUnit*> getEnemyUnitsInShootingRange(const int32& targetSquad, bool& friendlyFire);
    
    UFUNCTION(BlueprintCallable)
    bool getDebugFlag(FName flagName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FUnitDataStruct getData();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getCurrentEquipmentVariation(EEquipmentSlot equimentSlot);
    
    UFUNCTION(BlueprintCallable)
    ASMUnit* getBlockingLineVision(ASMUnit* unitA, ASMUnit* unitB);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMUnit*> getAllFamilyMembers();
    
    UFUNCTION(BlueprintCallable)
    AResource* FindNearestCart(const ASMBuildingMaster* belongsTo);
    
    UFUNCTION(BlueprintCallable)
    bool faceEnemy(bool clampRotation);
    
    UFUNCTION(BlueprintCallable)
    void equipWithAnimation(const int32& ItemType);
    
    UFUNCTION(BlueprintCallable)
    void equipTradeWagon();
    
    UFUNCTION(BlueprintCallable)
    bool equipResource(int32 goodID, bool freeHands);
    
    UFUNCTION(BlueprintCallable)
    void equipFromTemplate(const FUnitTemplate& Temp, const FName& tempName, bool bannerCarrier);
    
    UFUNCTION(BlueprintCallable)
    bool equipCosmeticOnly(int32 goodID);
    
    UFUNCTION(BlueprintCallable)
    void equipAdequateCivilianClothes(bool forceChange);
    
    UFUNCTION(BlueprintCallable)
    bool equip(int32 goodID, bool forceChange, bool useCarryingVariationIfPossible);
    
    UFUNCTION(BlueprintCallable)
    void drawDebugBoxAtLocation(const FVector& Location, FColor boxColor, float boxTime, FVector BoxSize);
    
    UFUNCTION(BlueprintCallable)
    void DrawDebugBox(FName debugFlag, FColor boxColor, float boxTime, FVector BoxSize);
    
    UFUNCTION(BlueprintCallable)
    bool doFarmingJobs(bool autoHarvestOnly, bool neverIgnoreWorkerLimit);
    
    UFUNCTION(BlueprintCallable)
    void despawnStaticGoodVisualization();
    
    UFUNCTION(BlueprintCallable)
    void despawnAllStaticGoodVisualizations();
    
    UFUNCTION(BlueprintCallable)
    void deathAnimationEnded();
    
    UFUNCTION(BlueprintCallable)
    void CombatHit(ASMUnit* attacker, ASMUnit* defender, bool isProjectile, float projDist, bool avoidKilling);
    
    UFUNCTION(BlueprintCallable)
    void changeMapVariationID(UPARAM(Ref) TMap<EEquipmentSlot, uint8>& variationMap, EEquipmentSlot Slot, int32 change);
    
    UFUNCTION(BlueprintCallable)
    void changeEquipmentVariation(EEquipmentSlot Slot, FName VariationName);
    
    UFUNCTION(BlueprintCallable)
    void cartLoadingUnequipGood();
    
    UFUNCTION(BlueprintCallable)
    void cartLoadingEquipGood();
    
    UFUNCTION(BlueprintCallable)
    bool capSpeedToPersonInFront(const FVector& currentLocation, const FVector& ProjectedLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool canSetPushStance(const EPushStance& stanceType);
    
    UFUNCTION(BlueprintCallable)
    bool canBeTrampled(ASMUnit* unit);
    
    UFUNCTION(BlueprintCallable)
    void calculateMorale(float adjustedTimeDelta);
    
    UFUNCTION(BlueprintCallable)
    bool anyoneFiringAlready();
    
    UFUNCTION(BlueprintCallable)
    bool anyActionInSquad(const int32& actionID);
    
    UFUNCTION(BlueprintCallable)
    void animationLoopEnded(bool intraLoop);
    

    // Fix for true pure virtual functions not being implemented
};

