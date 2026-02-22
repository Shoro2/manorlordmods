#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Color -FallbackName=Color
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Pawn -FallbackName=Pawn
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
#include "Army.h"
#include "Challenge.h"
#include "CinematicShot.h"
#include "Claim.h"
#include "EAmbienceType.h"
#include "EBehaviourStance.h"
#include "ECinematicEvent.h"
#include "ECursorMode.h"
#include "EItemCategory.h"
#include "EItemSubcategory.h"
#include "EMainUIMode.h"
#include "EPlotType.h"
#include "EPushStance.h"
#include "EQueuedUIUpdateType.h"
#include "ERTSTool.h"
#include "ERallyingStatus.h"
#include "EResidentialRequirement.h"
#include "ESettlementType.h"
#include "ETooltipTint.h"
#include "EUpdateType.h"
#include "EWallType.h"
#include "ExtractedPlot.h"
#include "FieldPoint.h"
#include "GlobalSettings.h"
#include "Good.h"
#include "Item.h"
#include "Letter.h"
#include "LogEntry.h"
#include "MercenaryCompany.h"
#include "OnPaperMapViewChangedDelegate.h"
#include "Paragraph.h"
#include "Problem.h"
#include "Quest.h"
#include "QuestMessage.h"
#include "RegionProviderInterface.h"
#include "Segment.h"
#include "Squad.h"
#include "SquadIcon.h"
#include "SquadTooltip.h"
#include "Tradepoint.h"
#include "UnitStat.h"
#include "UpgradeRequest.h"
#include "PawnCPP.generated.h"

class AActor;
class APawnCPP;
class ARTSMultiEngineCPP;
class ARegion;
class AResource;
class ARoad;
class ASMBuilding;
class ASMBuildingMaster;
class ASMUnit;
class AStaticMeshActor;
class UCameraComponent;
class UControlHook;
class UCurveFloat;
class UDataTable;
class UDecalComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMaterialParameterCollection;
class UMaterialParameterCollectionInstance;
class USkeletalMesh;
class USplineMeshComponent;
class USpringArmComponent;
class UStaticMesh;
class UStaticMeshComponent;
class UTextBlock;
class UTexture2D;
class UTextureRenderTarget2D;

UCLASS(Blueprintable)
class MANORLORDS_API APawnCPP : public APawn, public IRegionProviderInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPaperMapViewChanged onPaperMapViewChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARTSMultiEngineCPP* masterPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isMainPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isAI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCinematicTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpringArmComponent* Boom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraComponent* Camera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CameraAngleCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float cameraHeightMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float cameraHeightMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float zoomLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float smoothZoomLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float smoothZoomIncr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator smoothRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool b_ctrl_pressed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool shift_pressed_b;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool b_tab_pressed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool alt_pressed_b;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D LMB_pressed_2d;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D LMB_pressed_2d_scaled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RMB_pressed_b;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LMB_pressed_b;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool MMB_pressed_b;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float cameraRotateAxisValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMUnit* hoverUnit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHoversEnemy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> selectedSquads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 hoverSquadID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> rallyingSquadIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isUsingUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UControlHook* ControlHook;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollectionInstance* MPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* buildingMPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECursorMode cursorMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLogEntry> log;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 placeBuilding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* bbox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float workAreaPreviewRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* workAreaMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDecalComponent* rangeDecal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* rangeDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* roadDecal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* roadDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* roadPosDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* roadPosDecalMatOnRoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* buildingPreviewDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* extensionPreviewDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* marketPreviewDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* bPartPreviewDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDecalComponent* moveArrow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* ArrowMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* BoundsDecal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* boundsDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* circularBoundsDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* boundsDecalMat_Military;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* hitBuilding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuilding* hitBuildingPart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMBuildingMaster*> selectedBld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMBuildingMaster*> closeBuildings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle updateCloseHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector lastProximityCacheUpdateLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float lastZoomLevelProximityCacheUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARoad* dummyRoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> roadPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool roadmode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool roadRemoveMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector roadStartPos;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool roadStarted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool roadBuildHover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARoad* hoverRoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* plannerModeBld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool inPlanningMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* hoverBlueprint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* selectedBlueprint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* draggingBlueprint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector draggingBlueprint_StartLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator draggingBlueprint_StartRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 draggingRoadPointID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isDraggingGatePoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* rotationGizmo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float rotationGizmo_startYaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isDraggingRotationGizmo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isRotationGizmoHovered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float rotationGizmo_smoothOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* RT_modulePlanner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalSettings Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool hasClicked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D camVelo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString lordsName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool letterCreatorMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mapLerp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* deerDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* decal_dot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* decal_cross;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPlayerPaused;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARegion* currentRegion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARegion* regionUnderCursor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool markLoyaltyUIUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 numFieldDrainage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float camera_tilt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float camera_heightOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float camera_clearance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float roadTangentScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> commandedSquads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> activeCommandedSquads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> enemySquads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 silver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMainUIMode currentUIMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool cinematicMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool followMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* following;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 tabBeforeSwitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FQuest> proposedQuests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FQuest> questOpportunities;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float roadCurvatureBarOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRoadCurvatureChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool mapViewMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mapViewDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mapViewSpeedMul;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARegion* hoveringRegion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARegion* selectedRegion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float recruitCost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLogEntry> dismissedEntries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float lastActionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 lastQuestDay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FQuest> quests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> availablePolicies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isBandit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FClaim> claims;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 influence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 targetSquadSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> recruiting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 maxNumOfMilitiaToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool cameraMoved;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool cameraRotated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool cameraZoomed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APawnCPP*> enemies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor playerColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator fieldRot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> recruitmentPool_Mercs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> recruitmentPool_Militia;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> diplomaticTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FParagraph> letterHistory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLetter> InBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLetter> outbox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool wallMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRelationsEstablishd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool placeBuilding_isSnapped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 placeBuilding_snapVariation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isFemale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Portrait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 kingsFavour;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 predictedIncome;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float lastShoutSfx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSquadTooltip SquadTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool shouldUpdateArmyUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool shouldUpdateArmyListUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool shouldUpdateStatUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARegion* RegionPanelTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQueuedUIUpdateType RegionPanel_GoodListUpdateType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool shouldUpdateProblemUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool shouldUpdateClaimUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool shouldUpdateApprovalUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool shouldUpdateInventoryStorageUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool shouldUpdateResidentsUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldUpdateLivingSpaceUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float lastIconClickTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* firingRangeMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* firingRangeDynamicMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool firingRangeVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float firingRangeOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* unitColorDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* unitDecalDynamic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* unitDecalDynamic_selected;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSquadIcon> squadIconDrawList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> showDecalSquads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool weather_thunderStorm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DMS_battleIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DMS_tacticalRetreat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle DMS_update_handle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AResource*> resourcesInCollisionOfPlacebuilding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LMB_last_pressed_time;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float doubleclick_threshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPlotType placePlotType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool placeFieldMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isMarket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isExtension;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* extensionFor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool fieldCollides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFieldPoint> fieldPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFieldPoint> fieldPointsClosed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFieldPoint> fieldPointsRotated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> fieldSmoothPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> fieldSmoothPointsClosed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> fieldPreviewTriangulated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool fieldClosed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector fieldCenter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 fieldWorkersNeeded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float minimumBuildDistanceFromBorder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector lastKnownFieldPointPreviewPos;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isInsideBorders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D LastMousePos;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LastCameraPos;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool fieldPointsChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExtractedPlot> extractedPlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 slicingAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 numPlotOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 expectedNumPlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 maxDivisionsForThisPlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTransform> extensionTransforms;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTransform> marketTransforms;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USplineMeshComponent*> fieldSplineMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* fieldSpline_StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* M_fieldSplineDummy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 hoverProblem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> previewRoadDecals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* buildingPreviewPlane;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> previewBuildingDecals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> previewExtensionDecals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 marketShape;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETooltipTint tooltipTint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 predictedRoyalTaxes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 numTimesInDebt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* movedBuilding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> fieldPointMarkers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> markerAnimationTimes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_fieldMarker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHoversRoadCommit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool buildConfirmHovered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProblem lastPressedProblem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 whiteTooltipCorner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUpgradeRequest UpgradeRequest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUpgradeRequest artisanChangeRequest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUpgradeRequest extensionChangeRequest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMBuildingMaster*> demolishRequests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool commitFieldRequestPending;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool upgradeRequestPending;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool artisanChangeRequestPending;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool extensionChangeRequestPending;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool requestBuild;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Traits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool hasAnyActiveQuests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float foliageTransparencyAdd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool debugBoopMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMUnit* reassignMode_FamilyMember;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle animateDoorsHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float cameraLerpFrames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> lastVoiceResponses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* wallCursor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_Alerts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> visibleSquads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle squadVisiblityHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float smoothedConstrMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float dipToBlackOpacity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCinematicShot> cinematicShotQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCinematicShot currentCinematicShot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float currentCinematicShotElapsedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECinematicEvent cinematicOverEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool grayscaleTint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* plotToRoadSnappingHelperStaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> plotToRoadSnappingHelpers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float timeMarketDistributionHovered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMarketDistributionShowing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EResidentialRequirement marketDistributionOverlayCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EItemSubcategory marketDistributionOverlaySubcategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* marketResourceIconBgTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool shouldUpdateMarketStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERTSTool activeRTSTool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* RTSToolActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName activeRTSToolVariety;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> placebuilding_missingTech;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> tagAdditionDay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* squadPathArrowMesh;
    
    APawnCPP(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void withdrawAllClaimsAndChallengesTowards(APawnCPP* Pawn);
    
    UFUNCTION(BlueprintCallable)
    bool wasParagraphEverUsed(APawnCPP* sender, const FName& para);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateTradeUI();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateTownLabels();
    
    UFUNCTION(BlueprintCallable)
    void updateTooltip();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateStatUI();
    
    UFUNCTION(BlueprintCallable)
    void updateSquadVisibility();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateSoundFilters();
    
    UFUNCTION(BlueprintCallable)
    void updateShowDecalSquads();
    
    UFUNCTION(BlueprintCallable)
    void updateSelectionDecals(TArray<ASMUnit*> unitsToUpdate);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateRTSToolActorUI();
    
    UFUNCTION(BlueprintCallable)
    void updateRoadDecalVisibility();
    
    UFUNCTION(BlueprintCallable)
    void UpdateRetinuePreviewMeshTransform();
    
    UFUNCTION(BlueprintCallable)
    void updateResourceOutlines();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateResidentsUI();
    
    UFUNCTION(BlueprintCallable)
    void updateRecruitmentPool();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateQuestTimesUI();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateQuestlog();
    
    UFUNCTION(BlueprintCallable)
    void updateProjectedFieldCollision(bool checkSteepness, bool reprojectNoSnapIfCollides);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateProblemUI();
    
    UFUNCTION(BlueprintCallable)
    void updatePreviewRoadDecalsPos();
    
    UFUNCTION(BlueprintCallable)
    void updatePreviewBuildingDecalsPos();
    
    UFUNCTION(BlueprintCallable)
    void updatePlotToRoadSnappingHelperLocations();
    
    UFUNCTION(BlueprintCallable)
    void updatePlacebuildingMPC();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updatePlacebuildingMesh(int32 buildingID, bool isSnapped, int32 snapVariationID);
    
    UFUNCTION(BlueprintCallable)
    void updateOverlayDecalVisibility();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateOrderProgressUI(const ASMBuildingMaster* building);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateMercenayCompanyUI();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateMarketStats();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateLogUI();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateLivingSpaceUI();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateKingsFavourUI();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateInventoryStorage();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateInventoryFieldStatus();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateInventory(const EUpdateType UpdateType);
    
    UFUNCTION(BlueprintCallable)
    void updateHoveringRegion();
    
    UFUNCTION(BlueprintCallable)
    void updateHasAnyActiveQuests();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateGameSpeedUI();
    
    UFUNCTION(BlueprintCallable)
    void updateFieldPointMarkers();
    
    UFUNCTION(BlueprintCallable)
    void updateDiplomaticTags();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void updateDemolishAvailabilityInOpenedBuildingTabsUI();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateDateUI(int32 day, int32 Month, int32 season);
    
    UFUNCTION(BlueprintCallable)
    void updateCursor(ECursorMode NewMode);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateCurrentRegionUI();
    
    UFUNCTION(BlueprintCallable)
    void updateCurrentRegion();
    
    UFUNCTION(BlueprintCallable)
    void updateCommandedAndEnemySquads(bool includeFleeing);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateCoatOfArmsSymbol();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateClaimsUI();
    
    UFUNCTION(BlueprintCallable)
    void updateClaims();
    
    UFUNCTION(BlueprintCallable)
    void updateClaimBlocked(FClaim& Claim);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateCastleReconstructionCostUI();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void updateCastleConstructionAvailabilityUI();
    
    UFUNCTION(BlueprintCallable)
    void updateCameraClearance();
    
    UFUNCTION(BlueprintCallable)
    void UpdateBuildingProximityCache();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateBoopMode();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateAssignModeUI();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateApprovalUI();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void updateAnySaveMenu();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateActiveRTSToolUI();
    
    UFUNCTION(BlueprintCallable)
    void unPauseGame();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void triggerTutorialIfNeeded(FName tutorialMsg, const FVector& Location);
    
    UFUNCTION(BlueprintCallable)
    void triggerDefeat(const FName& EventTag, APawnCPP* byWho);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void toggleTimePause();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void toggleTimeNext();
    
    UFUNCTION(BlueprintCallable)
    void toggleSprint();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void togglePauseMenu();
    
    UFUNCTION(BlueprintCallable)
    void tickCinematicShot(float DeltaTime);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void tabBpReleased();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void tabBpPressed();
    
    UFUNCTION(BlueprintCallable)
    void tab_released();
    
    UFUNCTION(BlueprintCallable)
    void tab_pressed();
    
    UFUNCTION(BlueprintCallable)
    void switchWallMode(const bool& NewMode);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void switchTab(const int32& Tab);
    
    UFUNCTION(BlueprintCallable)
    void stopVAMP();
    
    UFUNCTION(BlueprintCallable)
    bool splitWallsByCastleModule(const AStaticMeshActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void spawnWorkAreaConfirmation(const FVector& Pos, const float& Radius);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void spawnWallJoinWidget(const ARoad* wallA, const ARoad* wallB);
    
    UFUNCTION(BlueprintCallable)
    void spawnPlotToRoadSnappingHelperLocations(int32 numHelpers);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void spawnCastleFloater(AActor* buildingModule);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void showSavingIcon();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void showProgressUpdate(ARegion* Region);
    
    UFUNCTION(BlueprintCallable)
    bool shouldShowFieldPreview();
    
    UFUNCTION(BlueprintCallable)
    void setWorkAreaMode(ASMBuildingMaster* building);
    
    UFUNCTION(BlueprintCallable)
    void setUIScale(float NewScale);
    
    UFUNCTION(BlueprintCallable)
    void settleRegion(ARegion* regionToSettle, const FTransform& SettlersCampLocation, uint8 supplyLevel, ESettlementType settlementType, ARegion* outpostToRegion);
    
    UFUNCTION(BlueprintCallable)
    void setSquadName(int32 squadID, const FString& NewName);
    
    UFUNCTION(BlueprintCallable)
    void setShowPlotToRoadSnappingHelpers(bool shouldShow);
    
    UFUNCTION(BlueprintCallable)
    void SetSettings(FGlobalSettings newSettings);
    
    UFUNCTION(BlueprintCallable)
    void setRoadMode(bool Mode, FVector StartPos, bool Started);
    
    UFUNCTION(BlueprintCallable)
    void setReassignMode(ASMUnit* FamilyMember);
    
    UFUNCTION(BlueprintCallable)
    void SetPreviewWorkAreaMode(ASMBuildingMaster* building);
    
    UFUNCTION(BlueprintCallable)
    void SetPosition(const FVector& newPos);
    
    UFUNCTION(BlueprintCallable)
    void setPlannerMode(ASMBuildingMaster* setPlannerBuilding);
    
    UFUNCTION(BlueprintCallable)
    void setPlaceRallyingPoint(TArray<int32> squadIDs);
    
    UFUNCTION(BlueprintCallable)
    void setPlacedBuilding(int32 newPlacedBuilding);
    
    UFUNCTION(BlueprintCallable)
    void setMapMode(const bool& newMapMode);
    
    UFUNCTION(BlueprintCallable)
    void setMapLerp(const float& NewValue);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void setMainUIMode(EMainUIMode NewMode);
    
    UFUNCTION(BlueprintCallable)
    void setLocationAboveGround(UPARAM(Ref) FVector& NewPosition, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void SetLMBReleased(bool isLMBReleased);
    
    UFUNCTION(BlueprintCallable)
    void setLetterCreatorMode(const bool NewMode);
    
    UFUNCTION(BlueprintCallable)
    void setIsUsingUI(bool newFlag);
    
    UFUNCTION(BlueprintCallable)
    void setIsUsingLowTopBars(const bool& newFlag);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void setInventoryTabForBuilding(ASMBuildingMaster* building, int32 inventoryTabIndex);
    
    UFUNCTION(BlueprintCallable)
    void SetGoodCounterWidget(int32 goodType, bool bAlternativeWidget, UTextBlock* WidgetToSet);
    
    UFUNCTION(BlueprintCallable)
    void setGameSpeed(const float newSpeed);
    
    UFUNCTION(BlueprintCallable)
    void setFollowMode(AActor* actorToFollow, bool playSfx);
    
    UFUNCTION(BlueprintCallable)
    void setFieldMode(bool NewMode, bool _isExtension, bool _isMarket, EPlotType plotType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void setDipToBlackOpacity(float Opacity);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void setCinematicMode(bool NewMode);
    
    UFUNCTION(BlueprintCallable)
    void setChoice(FName newChoice, int32 questID);
    
    UFUNCTION(BlueprintCallable)
    void SetCategoryCounterWidget(EItemCategory Category, UTextBlock* WidgetToSet);
    
    UFUNCTION(BlueprintCallable)
    void setBuildingSelected(ASMBuildingMaster* building, bool newSelected);
    
    UFUNCTION(BlueprintCallable)
    void setBuildingMesh(UStaticMesh* Mesh);
    
    UFUNCTION(BlueprintCallable)
    void setBorderVisibility(bool newSetting);
    
    UFUNCTION(BlueprintCallable)
    void setAllBuildingMeshesHidden(bool hidden);
    
    UFUNCTION(BlueprintCallable)
    void sendLetter(APawnCPP* recipient, const TArray<FName>& Letter);
    
    UFUNCTION(BlueprintCallable)
    void selectSquad(int32 squadID, bool resetSelection, bool playSounds);
    
    UFUNCTION(BlueprintCallable)
    void selectHoveredBuilding();
    
    UFUNCTION(BlueprintCallable)
    void selectCastleBlueprint(AActor* Blueprint, bool turnOnFollowMode);
    
    UFUNCTION(BlueprintCallable)
    void selectBuildingSilent(ASMBuildingMaster* bld);
    
    UFUNCTION(BlueprintCallable)
    void saveScreenshot();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RMB_BP_released();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RMB_BP_pressed();
    
    UFUNCTION(BlueprintCallable)
    void ReverseSelectedWall();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void respawnTownNames();
    
    UFUNCTION(BlueprintCallable)
    void respawnSquadPathArrows(int32 squadID);
    
    UFUNCTION(BlueprintCallable)
    void respawnPreviewRoadDecals();
    
    UFUNCTION(BlueprintCallable)
    void respawnPreviewBuildingDecals();
    
    UFUNCTION(BlueprintCallable)
    bool requestSaveFile(const FString& SlotName, const FString& saveName);
    
    UFUNCTION(BlueprintCallable)
    void reorderUnitCard(int32 squadID, int32 newIndex);
    
    UFUNCTION(BlueprintCallable)
    void renameSquad(int32 squadID, const FString& NewName);
    
    UFUNCTION(BlueprintCallable)
    void removeSquad(int32 squadID);
    
    UFUNCTION(BlueprintCallable)
    void removeRoad(ARoad* roadToRemove);
    
    UFUNCTION(BlueprintCallable)
    void removeOpportunity(FQuest opportunityToRemove);
    
    UFUNCTION(BlueprintCallable)
    void removeLogEntry(const FLogEntry& Entry);
    
    UFUNCTION(BlueprintCallable)
    void removeLastRoadPoint();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void removeChallengeFromUI(int32 challengeID);
    
    UFUNCTION(BlueprintCallable)
    void refuteClaim(UPARAM(Ref) FClaim& claimToRefute, bool useFavour);
    
    UFUNCTION(BlueprintCallable)
    void refuseQuest(const FQuest& Quest);
    
    UFUNCTION(BlueprintCallable)
    void recalculateRoyalTaxes();
    
    UFUNCTION(BlueprintCallable)
    void rallySquads(TArray<int32> squadIDs, FTransform rallyPointTransform);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void QuestMessage(const FQuest& Quest);
    
    UFUNCTION(BlueprintCallable)
    void projectResidentialAndUpdateUI();
    
    UFUNCTION(BlueprintCallable)
    void projectMarketplace();
    
    UFUNCTION(BlueprintCallable)
    void projectHoldSquad(int32 squadID);
    
    UFUNCTION(BlueprintCallable)
    void projectFormation(int32 squadID, const FVector& Pos, const FVector& sourceOverride, const FVector& facingTargetOverride);
    
    UFUNCTION(BlueprintCallable)
    void projectField(bool snap);
    
    UFUNCTION(BlueprintCallable)
    void projectCircularBorder(const FVector& Center, float diameter, TArray<FVector>& outSmoothBorder, TArray<FVector>& outBorder);
    
    UFUNCTION(BlueprintCallable)
    void projectAttackFormation(TArray<ASMUnit*> attackers, TArray<ASMUnit*> defenders, bool alwaysDirect);
    
    UFUNCTION(BlueprintCallable)
    void projectArmyFormation(const TArray<int32>& squads, const FVector& Pos, FVector sourceOverride, const uint8 floor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void positionRoadConfirm(const FVector& NewPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void pleaseTurnMapView(bool NewMode);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void playVoiceResponse(const FName& responseKey, const int32& voiceID, ASMUnit* relatedUnit);
    
    UFUNCTION(BlueprintCallable)
    void playVoiceline(const TArray<FName>& audioTags, const FVector& Pos, bool allowOverlap);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void playUISnd(int32 Type);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void playSaveFinishedNotif();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void playQuestMessage(const FQuest& Quest);
    
    UFUNCTION(BlueprintCallable)
    void playPopupMessageIfNotPlayedRecently(FName MessageType, ARegion* Region);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void playPopupMessageGUI(FName MessageType, ARegion* Region);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void playParticleSystem(const int32& ID, const FVector& Pos);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void playMessage(FQuestMessage Message, const int32& questID);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void playMarkerSound(const int32& snd);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void playKillCam(const FVector& Pos);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void playFeedbackText(const FString& Text, const FVector& Pos, float Speed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void playEventMessage(const FName& msgType, const FString& primaryText, const FString& secondaryText);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void playEventComplexMessage(const FName& msgType, const TArray<FString>& primaryText, const TArray<FString>& secondaryText);
    
    UFUNCTION(BlueprintCallable)
    void playCinematicSequence(TArray<FCinematicShot> shotSequence, ECinematicEvent afterItsOver);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void playCameraShake(const int32& typeOfShake, AActor* DebugActor, const FString& Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void playBuildingSound(const int32& bType);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void playBuildEffects(const FVector& Position);
    
    UFUNCTION(BlueprintCallable)
    void playAlertFromTag(FName alertTag);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void playAlert(const int32& Type);
    
    UFUNCTION(BlueprintCallable)
    void placeFieldDummy(bool forceChange);
    
    UFUNCTION(BlueprintCallable)
    FName pickVoiceResponse(ASMUnit* peasant, bool rare);
    
    UFUNCTION(BlueprintCallable)
    void performCustomQuestTriggers(const TArray<FName>& triggerNames, APawnCPP* recipient);
    
    UFUNCTION(BlueprintCallable)
    void pauseGame();
    
    UFUNCTION(BlueprintCallable)
    void PaperMapViewChanged(bool bIsPaperMap);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void openSettlementInitializer(ARegion* Region);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void openCastlePlannerUI(ASMBuildingMaster* plannerBuilding);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void openBuildingTab(ASMBuildingMaster* building, bool playSfx);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnWindowFocusChanged(bool bIsFocused);
    
    UFUNCTION(BlueprintCallable)
    void onSavingFinished();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float measureSquadPowerFromTemplate(FName& UnitTemplate);
    
    UFUNCTION(BlueprintCallable)
    float measureSquadPower(const int32& squadID, bool onlyMelee) const;
    
    UFUNCTION(BlueprintCallable)
    void MarkLogIndexAsDisplayed(const int32 Index);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool logExists(const FLogEntry& LogEntry, bool includeDismissed);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void LMB_BP_released();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void LMB_BP_pressed();
    
    UFUNCTION(BlueprintCallable)
    bool letter_hasAnyParagraphs(const TArray<FName>& currentLetter, const TArray<FName>& paras);
    
    UFUNCTION(BlueprintCallable)
    bool letter_hasAllRequired(const TArray<FName>& currentLetter, const TArray<FName>& requiredParas);
    
    UFUNCTION(BlueprintCallable)
    bool letter_containsPara(const TArray<FName>& currentLetter, const FName& para);
    
    UFUNCTION(BlueprintCallable)
    void layClaim(ARegion* Region, bool useFavour, bool consumeInfluence);
    
    UFUNCTION(BlueprintCallable)
    bool joinWalls(ARoad* wallA, ARoad* wallB);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isTaxFixed(int32 taxTypeID);
    
    UFUNCTION(BlueprintCallable)
    void issueRaiderTrackingQuestIfNew(int32 daysUntilRaid);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isStanceActivatedForSelected(bool isPushStance, const EPushStance& _pushStance, const EBehaviourStance& _behaviourStance);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isSquadSelected(int32 squadID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isSquadFleeing(int32 squadID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isSkillAvailableForSelectedSquads(int32 skillID, TArray<FName>& outReasonsNot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSelectEnemyBuildingOverrideEnabled();
    
    UFUNCTION(BlueprintCallable)
    bool isRoadGuidePoint(const FVector& Point);
    
    UFUNCTION(BlueprintCallable)
    bool isInAnyConstructionMode();
    
    UFUNCTION(BlueprintCallable)
    bool isCurrentlyInBattle();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isBuildingHovered();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isAnySquadRaiding(const FArmy& Army);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void invokeRemoveRoadPrompt(ARoad* roadToRemove);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void iconPop(ASMBuildingMaster* building, int32 Type);
    
    UFUNCTION(BlueprintCallable)
    int32 howManyDayAgoSentParagraph(const FName& para, APawnCPP* recipient);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HomeShortcut_pressed();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void highlightTargetBuilding(ASMBuildingMaster* building);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasTechAnyRegion(const int32& ID, int32 tier);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasActiveQuestNamed(const FString& questName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getWorkAreaMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getWallJoiningLocation(const ARoad* wallA, const ARoad* wallB);
    
    UFUNCTION(BlueprintCallable)
    float getUIScale();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FTradepoint> getTradeDeals();
    
    UFUNCTION(BlueprintCallable)
    float getTotalRecruitmentCost(const TArray<FName>& recruitment);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D getTaxRange(int32 taxTypeID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMUnit*> GetSquadUnits(const int32& squadID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName getSquadStatus(const int32& squadID);
    
    UFUNCTION(BlueprintCallable)
    TArray<int32> getSquadsNearPos(const FVector& Pos, const float& rangeSq, const TArray<int32>& squads);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APawnCPP* getSquadOwner(const int32& squadID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getSquadEquipmentAmt(int32 squadID, int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> getSquadControlGroups(int32 squadID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString getSquadCompanyName(int32 squadID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSquad getSquadByID(int32 squadID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FString> getSmallTooltip();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString getSetupPortraitName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGlobalSettings getSettings();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMBuildingMaster*> getSelectedBuildings();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getSelectedBuildingBlueprintUpgradeLevel(int32& buildingType, EWallType& wallType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMUnit*> GetSelected();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getRoadTangentScale();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getRoadMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ERallyingStatus getRetinueRallyingStatus(ARegion* Region);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ARegion*> getRelevantClaimedRegions(bool includeChallenges);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FChallenge> getRelevantChallenges();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getRelationsWith(APawnCPP* Pawn);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getRectB();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D getRect();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> getRecruitmentPool(bool mercenaries);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FQuest> getQuestsWithFocus(FName focus);
    
    UFUNCTION(BlueprintCallable)
    TArray<FQuest> getQuests();
    
    UFUNCTION(BlueprintCallable)
    bool getPreviousLetterFromThisPawn(APawnCPP* Pawn, FLetter& Letter);
    
    UFUNCTION(BlueprintCallable)
    bool getPreviousLetterFromConversation(APawnCPP* Pawn, FLetter& Letter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARegion* getPreviousCommandedRegion(ARegion* InCurrentRegion);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMUnit*> getPlayersOxen();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getPawnSetupIndex();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> getOrderedSquadList();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumYearsSurvived();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void getNumShowingQuestMessages(int32& Num);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getNextProblemOfType(const int32& Type, FProblem& outProblem, ARegion* Region);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARegion* getNextCommandedRegion(ARegion* InCurrentRegion);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getNearestRoadLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getMouseLMBdist();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getMouse3d();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D getMouse();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getMonthIDFromWeatherMaster();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getMapMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMBuildingMaster*> getManors();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ARegion*> getMainTowns();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void getMainTabIndex(int32& mainTabIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSoftObjectPtr<USkeletalMesh> getLordVisitModeSkeletalMesh();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString getLordsName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FLogEntry> getLog();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getLMBPressedB();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getLetterCreatorMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getKingsFavourPlace();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<APawnCPP*> getKingsFavourite();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getKingsFavour_daysLeft();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FItem getItem(int32 ItemId);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getIsWinter();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getIsUsingUI();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASMBuildingMaster* getHitBuilding();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void getHiredMercenaryCompanies(TArray<int32>& squads, TArray<int32>& companyIDs, TArray<FMercenaryCompany>& companies, bool bIncludeFleeing);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getGameSpeed();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getFieldModeClosed();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getFieldMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getFieldCenter();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getDummyCollision();
    
    UFUNCTION(BlueprintCallable)
    float getDistSqToNearestPlannerStaticModule(const FVector& Pos, FVector& outModulePos);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getDaysUntilCompanyGetsPaid(int32 comapnyID);
    
    UFUNCTION(BlueprintCallable)
    int32 getdaysSinceLastExtortionAttempt(APawnCPP* byPawn);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getDayOfTheYear();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getDayOfTheMonthFromWeatherMaster();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getCurrentYear();
    
    UFUNCTION(BlueprintCallable)
    FSegment getCurrentSquadLineProjection(int32 squadID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARegion* getCurrentRegion();
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> getCurrentlyAvailableParagraphs(const TArray<FName>& currentLetter, APawnCPP* recipient, bool includeCantAfford);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getCompanyCostForPawn(const FMercenaryCompany& company);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMBuildingMaster*> getCommandedBuildings();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARegion* getClosestRegion() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getCinematicMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FUnitStat getAverageUnitStat(const FName& Temp);
    
    UFUNCTION(BlueprintCallable)
    FVector getAverageFacingDirection(const TArray<int32>& squads, TArray<FVector>& outDirs);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FUnitStat getAverageEquipmentStat(const TArray<int32>& Items);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EAmbienceType getAmbienceTypeOnPosition(const FVector& Pos);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FSquad> getAllSquads();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FSquad> getAllCommandedSquads();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ARegion*> getAllCommandedRegions();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMUnit*> getAllCommandedMilitaryUnits();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void gameOver(const int32& Type);
    
    UFUNCTION(BlueprintCallable)
    void formALineArmy(const TArray<int32>& squads, const FSegment& line, const FName& formationType, FSegment lastCommandedLineArmy);
    
    UFUNCTION(BlueprintCallable)
    void formALine(const TArray<ASMUnit*>& unitArr, const FVector& Start, const FVector& End, const uint8 floor);
    
    UFUNCTION(BlueprintCallable)
    void finishQuestByIndex(const int32& questID, const bool& Success, const bool& Remove);
    
    UFUNCTION(BlueprintCallable)
    void finishQuest(FQuest& Quest, bool Success, bool Remove);
    
    UFUNCTION(BlueprintCallable)
    void finishCinematicSequence();
    
    UFUNCTION(BlueprintCallable)
    TArray<ASMUnit*> findUnitsDoingAction(int32 ActionType, APawnCPP* ownerPawn);
    
    UFUNCTION(BlueprintCallable)
    TArray<FVector> findSharpPoints(const TArray<FVector>& Path, TArray<float>& props, const bool& parallelOnly);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARegion* findRegionByName(const FString& regionName);
    
    UFUNCTION(BlueprintCallable)
    bool findNearestWallSnapPoint(const FVector& Loc, float maxDistSq, FVector& OutLocation, float& outDistSq);
    
    UFUNCTION(BlueprintCallable)
    bool findNearestRoadpoint(const ARegion* Region, const FVector& Position, FVector& OutNearestRoadpoint, bool bOnlyKingsRoad) const;
    
    UFUNCTION(BlueprintCallable)
    FVector findNearestMapEdge(const FVector& Position, float& outDistSq);
    
    UFUNCTION(BlueprintCallable)
    float findFormationDepth(const int32& squadID);
    
    UFUNCTION(BlueprintCallable)
    TArray<ARoad*> findCommonRoads(const TArray<ARoad*>& roadsA, const TArray<ARoad*>& roadsB);
    
    UFUNCTION(BlueprintCallable)
    FVector findClosestPositionOnSegments(const FVector& Point, const TArray<FVector>& available);
    
    UFUNCTION(BlueprintCallable)
    FVector findClosestPosition(const FVector& Point, const TArray<FVector>& available);
    
    UFUNCTION(BlueprintCallable)
    void finalizeClaim(ARegion* Region, bool Remove);
    
    UFUNCTION(BlueprintCallable)
    void fieldRemovePoint();
    
    UFUNCTION(BlueprintCallable)
    void fieldAddPoint();
    
    UFUNCTION(BlueprintCallable)
    float fastSqrt(const float& N);
    
    UFUNCTION(BlueprintCallable)
    TArray<FVector> extractSmoothSide(const TArray<FVector>& SmoothBorder, const FVector& cornerA, const FVector& cornerB);
    
    UFUNCTION(BlueprintCallable)
    TArray<FVector> extractIntersected(const TArray<FVector>& smoothSegment, const FSegment& intersectionA, const FSegment& intersectionB, const bool& intersectA, const bool& intersectB);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void eraseBuildingReferencesFromUI(ASMBuildingMaster* building);
    
    UFUNCTION(BlueprintCallable)
    bool enactPolicy(ARegion* Region, const int32& slotNo, const int32& policyID);
    
    UFUNCTION(BlueprintCallable)
    void drawSquadOverlays();
    
    UFUNCTION(BlueprintCallable)
    void drawBuildingOverlays();
    
    UFUNCTION(BlueprintCallable)
    bool doesPlacebuildingAffectDeerLair();
    
    UFUNCTION(BlueprintCallable)
    void DMS_updateBattleIntensity();
    
    UFUNCTION(BlueprintCallable)
    void disbandSquad(int32 squadID);
    
    UFUNCTION(BlueprintCallable)
    void destroySelectedCastleBlueprint();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void despawnWallJoinWidgetIfExists();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void despawnCastleFloater();
    
    UFUNCTION(BlueprintCallable)
    void deselectSquad(int32 squadID);
    
    UFUNCTION(BlueprintCallable)
    void deselectCastleBlueprint();
    
    UFUNCTION(BlueprintCallable)
    void deselectBuilding(ASMBuildingMaster* building);
    
    UFUNCTION(BlueprintCallable)
    void deselect_buildings();
    
    UFUNCTION(BlueprintCallable)
    void Deselect();
    
    UFUNCTION(BlueprintCallable)
    void declareWar(APawnCPP* targetPawn);
    
    UFUNCTION(BlueprintCallable)
    void declarePeace(APawnCPP* targetPawn);
    
    UFUNCTION(BlueprintCallable)
    void createDynamicUnitDecalMaterialIfNecessary();
    
    UFUNCTION(BlueprintCallable)
    void createAndPlayVictoryCinematic();
    
    UFUNCTION(BlueprintCallable)
    void createAndPlayGameOverCinematic();
    
    UFUNCTION(BlueprintCallable)
    void constructionComplete(ASMBuildingMaster* building);
    
    UFUNCTION(BlueprintCallable)
    ARoad* commitRoad();
    
    UFUNCTION(BlueprintCallable)
    ASMBuildingMaster* commitField();
    
    UFUNCTION(BlueprintCallable)
    bool collectsAnyTaxes();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CloseInventoryTabIfOpen(ASMBuildingMaster* building);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void closeAllTabs();
    
    UFUNCTION(BlueprintCallable)
    void clearBufferedMovement();
    
    UFUNCTION(BlueprintCallable)
    void checkAndTriggerGameOver();
    
    UFUNCTION(BlueprintCallable)
    void ChangeTreasury(const int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    void changeSilver(int32 amt);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void changeSelectedRegionUI(ARegion* newSelectedRegion);
    
    UFUNCTION(BlueprintCallable)
    void changeSelectedBuildingPlatformLevel(int32 levelChange);
    
    UFUNCTION(BlueprintCallable)
    void changeSelectedBuildingBlueprintUpgradeLevel(int32 levelChange);
    
    UFUNCTION(BlueprintCallable)
    void changeRelationTags(APawnCPP* pawnB, const TArray<FName>& addTags, const TArray<FName>& removeTags);
    
    UFUNCTION(BlueprintCallable)
    void changeRelations(APawnCPP* pawnB, const float& change);
    
    UFUNCTION(BlueprintCallable)
    void changePlotOffset(int32 change);
    
    UFUNCTION(BlueprintCallable)
    void changeLetterRead(const FLetter& letterToChange, bool bLetterRead);
    
    UFUNCTION(BlueprintCallable)
    void changeKingsFavour(const int32& change);
    
    UFUNCTION(BlueprintCallable)
    void changeInfluence(const float& change);
    
    UFUNCTION(BlueprintCallable)
    void changeActiveRTSTool(ERTSTool newTool, AActor* toolActor, FName toolVariety);
    
    UFUNCTION(BlueprintCallable)
    void castlePlanningTools();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool canClaimSomething();
    
    UFUNCTION(BlueprintCallable)
    bool canChangeSelectedBuildingPlatformLevel(int32 levelChange);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool canChangeSelectedBuildingBlueprintUpgradeLevel(int32 levelChange);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool canAddNewMilitiaSquad(ARegion* inRegion);
    
    UFUNCTION(BlueprintCallable)
    void cameraMovement(float deltaT);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void callCommitRoad();
    
    UFUNCTION(BlueprintCallable)
    int32 calculateFieldWorkersNeeded(const TArray<FVector>& Points);
    
    UFUNCTION(BlueprintCallable)
    void beginNextQueuedCinematicShot();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void armyUIUpdate();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void armyListUIUpdate();
    
    UFUNCTION(BlueprintCallable)
    bool anyArchersSelected();
    
    UFUNCTION(BlueprintCallable)
    void animateDoorsCrude();
    
    UFUNCTION(BlueprintCallable)
    bool allArchersWithinRange(const int32& squadID, const int32& TargetId);
    
    UFUNCTION(BlueprintCallable)
    void AffectAnimalLairs(ASMBuildingMaster* building);
    
    UFUNCTION(BlueprintCallable)
    void addUpgradeRequest(FUpgradeRequest newRequest);
    
    UFUNCTION(BlueprintCallable)
    void addTradeDeal(const FTradepoint& newDeal);
    
    UFUNCTION(BlueprintCallable)
    void addToOutbox(const FLetter& newLetter);
    
    UFUNCTION(BlueprintCallable)
    void addToInbox(const FLetter& newLetter);
    
    UFUNCTION(BlueprintCallable)
    void addTagRememberDay(const FName& newTag);
    
    UFUNCTION(BlueprintCallable)
    void addRetinueSquad(ARegion* Region);
    
    UFUNCTION(BlueprintCallable)
    void addResourceAddedLogs(const TArray<FGood>& newInventory, ASMBuildingMaster* building);
    
    UFUNCTION(BlueprintCallable)
    void addRemoveSquadRequest(int32 squadID);
    
    UFUNCTION(BlueprintCallable)
    void addMilitiaSquad(ARegion* Region, FName unitType);
    
    UFUNCTION(BlueprintCallable)
    void addLogIfNew(const FName& Tag, const FString& Text, const FString& descr, int32 opensMenu, const FVector& Pos, AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void addLog(const FName& Tag, const FString& Text, const FString& descr, int32 opensMenu, const FVector& Pos, AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void addExtensionChangeRequest(FUpgradeRequest newRequest);
    
    UFUNCTION(BlueprintCallable)
    void addCommitFieldRequest();
    
    UFUNCTION(BlueprintCallable)
    void addArtisanChangeRequest(FUpgradeRequest newRequest);
    
    UFUNCTION(BlueprintCallable)
    void acceptQuest(UPARAM(Ref) FQuest& Quest);
    

    // Fix for true pure virtual functions not being implemented
};

