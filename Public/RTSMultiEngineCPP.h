#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Box2D -FallbackName=Box2D
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Color -FallbackName=Color
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Quat -FallbackName=Quat
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=SoftClassPath -FallbackName=SoftClassPath
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=SoftObjectPath -FallbackName=SoftObjectPath
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector4 -FallbackName=Vector4
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
#include "Army.h"
#include "BBorder.h"
#include "BuildingSpawnParams.h"
#include "Challenge.h"
#include "DefferedMeshLoadItem.h"
#include "EApprovalFactorType.h"
#include "ECropType.h"
#include "EItemSubcategory.h"
#include "EUnitRole.h"
#include "Equipment.h"
#include "Good.h"
#include "Item.h"
#include "LorePoint.h"
#include "MercenaryCompany.h"
#include "Obstacle2D.h"
#include "OpenClaim.h"
#include "Pair.h"
#include "PopupCache.h"
#include "Relation.h"
#include "Segment.h"
#include "Segment2D.h"
#include "SessionAchievementData.h"
#include "Squad.h"
#include "Stat.h"
#include "Templates/SubclassOf.h"
#include "TradeLogEntry.h"
#include "Triangle.h"
#include "UnitStat.h"
#include "Upgrade.h"
#include "RTSMultiEngineCPP.generated.h"

class AConstruction;
class ADecalActor;
class ADepositDecal;
class ADirector;
class APawnCPP;
class ARegion;
class AResource;
class ARoad;
class ASMBanner;
class ASMBuilding;
class ASMBuildingMaster;
class ASMUnit;
class ASmoothForce;
class ASoundBuddy;
class AUnitSpawner;
class AWeatherMaster;
class UAnimSequenceBase;
class UBannerAnimInstance;
class UCanvas;
class UDataTable;
class UFoliageInstancedStaticMeshComponent;
class UMaterialInterface;
class UMaterialParameterCollection;
class UParticleSystem;
class UParticleSystemComponent;
class URuntimeVirtualTexture;
class USceneComponent;
class USkeletalMesh;
class USnapDebris;
class USphereReflectionCaptureComponent;
class UStaticMesh;
class UStaticMeshComponent;
class UTexture2D;
class UTextureRenderTarget2D;
class UVARuntimeComponent;

UCLASS(Blueprintable)
class MANORLORDS_API ARTSMultiEngineCPP : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Delta;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float gameSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool spawnAIPlayers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool declareWarInstant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AI_canBuild;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> unitArr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_WindmillShaft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CullDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float cullDistanceFar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float cullDistanceMid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float cullDistanceClose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float cullDistanceBuildings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_ConstructionBPs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AnimsetCombat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AnimsetWork;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AnimsetGoat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AnimsetChicken;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AnimsetSheep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AnimsetDeer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AnimsetHorse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AnimsetBird;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AnimsetOx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AnimsetHound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AnimsetPig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AnimsetHare;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AnimsetCombined;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMBuildingMaster*> buildingArr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMBuildingMaster*> independentBuildings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AConstruction*> collapsingConstructions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* buildingMPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MPC_Overlays;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ARegion*> Regions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ARoad*> borders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ARoad*> bordersCameraBlocking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ARoad*> roads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ARoad*> streams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSquad> squads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> playersSquadsUIOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTexture2D*> regimentSymbols;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* RT_fields;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* RT_plowing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* RT_Fertility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* RT_ForestMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* RT_Desirability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCanvas* Canvas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* RT_RegionMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* RT_RegionBorderMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* RT_roads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* RT_holes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* RT_veins;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* dirtPattern01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* dirtPattern01Scaled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* marketPattern;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* softMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* softMaskScaled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* pitMaskTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* pitMaskDirt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* pitMaskNew;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_socketMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* itemStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UMaterialInterface*> paperMapResourceMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UMaterialInterface*> resourceZoneMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector paperMapMaskOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mapMiddleHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float mapFadeDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ADepositDecal*> deposits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* depositMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* depositMaterial_Salt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* depositMaterial_Clay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UFoliageInstancedStaticMeshComponent> foliageCustomDataBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> youngTreeMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> treeMeshesTriggeringForestBiome;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> fieldBorderMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> fieldstoneMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResource> treeBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResource> iranyriveresourceBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResource> stoneResourceBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResource> beeResourceBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResource> shrubResourceBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResource> shroomResourceBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResource> handcartResourceBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResource> bigcartResourceBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResource> fishResourceBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResource> ladderResourceBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResource> ironResourceBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResource> clayResourceBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResource> saltResourceBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AWeatherMaster* WMaster;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ThunderLightBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_arrow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_torch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USnapDebris* SnapDebris;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASoundBuddy* SoundBuddy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_resourceSounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> unitsMarkedForDestruction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_dustPuff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_BLoodSplatter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_Thunder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_dragDust;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_Impact_Smithing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_Impact_Leaves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_Impact_Wood;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_Impact_WoodDry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_Impact_Stone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_Impact_Plow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_Impact_PloughHeavy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_Impact_Sow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_fireBig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_fireGrid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_fireplaceSmoke;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_chimneySmoke;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_malthouseSmoke;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_Splash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_BucketSplash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_FlourPuff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_ThunderHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_FieryHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_Bees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_TorchImpact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PS_fallingLeaves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FUpgrade> upgrades;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle textureUpdateHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle asyncCleanupTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle challengeUpdateTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 predictionCalculationDays;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float locationUpdateCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMBuildingMaster*> fieldArr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* fieldRTmat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* M_marketDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* workDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* moduleMaskMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* M_overlay_moduleMasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* M_overlay_fertility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 updatePosLag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 lastUniqueID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> tradeableGoods;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> SpoilingGoodTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> GranaryCollectionTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> treeMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> shrubMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> oreMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> recruitmentPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMBuildingMaster*> tradepoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float basePrice;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_units;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool fogOfWar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle ambientVoiceHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle projUpdateHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRelation> relations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MapSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UBannerAnimInstance> bannerAnimBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASMBanner> bannerBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FOpenClaim> openClaims;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 kingsFavour_daysLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APawnCPP*> kingsFavourite;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* ghostMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_MercenaryCompanies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMercenaryCompany> availableMercs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, FMercenaryCompany> hiredMercs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTexture2D*> availableLordPortraits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTexture2D*> availableBanditPortraits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool prepareRoadsForEditor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool enableFertilityGrid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLinearColor> fertilityGrid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLinearColor> fertilityGridLimits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool instancePositionUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float deltaDiff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> AI_buildingTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> livestockMerchants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> freeMerchants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 traderTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isConstructionAllowed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool dustyMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool spawnMerchants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool canRain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool canSnow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle updateArmiesHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASmoothForce*> smoothForces;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ADecalActor> bloodDecalBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> heads_combat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool drawBattleDebug;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool drawImportantDebug;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool drawPathfindingDebug;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool drawDebg_roadGuidePoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* plagueDecalMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> maleNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool unitJustSpawned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* boundsDecalMatRoadsOK;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* sidewalkMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_fence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_fence_B;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_plankFence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* townwallMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_palisade;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_stoneWall;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> SM_stoneWall_pieces;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> SM_stoneWall_platforms;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> doorMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> stairMeshesWooden;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> stairMeshesStone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_storage_log;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* SM_banner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_Upgrades;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* borderSegmentMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_FatRoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_shrubbyMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float lastVeloUpdTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle propagationHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDefferedMeshLoadItem> deferredMeshLoadList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FObstacle2D> obstacles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URuntimeVirtualTexture* RVT_Landscape;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URuntimeVirtualTexture* RVT_RoadMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URuntimeVirtualTexture* RVT_Heightmap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URuntimeVirtualTexture* RVT_ModuleMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URuntimeVirtualTexture* RVT_SnowDisplacementMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* fieldMaskMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* marketMaskMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* vegetableFieldMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> cliffObstacles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_BuildingPartAssemblies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_BuildingPartMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_gameplayStaticMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FSoftClassPath> independentBuildingAssemblies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FSoftClassPath> animatedBuildingBlueprints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> plantMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> lazyBuildings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_wheat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_flax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_willowBranches;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_herbs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_appleTree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_appleTree_old;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FChallenge> challenges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMBuildingMaster*> retinueSpawnRequests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector defaultFallenTreeScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* empty_instance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SM_dirtPlane;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> SM_AnimalTraps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UStaticMesh*> wallMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ADirector* questDirector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float lastObstructionYaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle fertilityRedrawHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> fertilityGridUpdateRequests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* workAreaMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequenceBase* testAnimClip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* testSzkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* marketfieldMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* roadConnectionMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMBuilding*> spawnAsyncConstrBpQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle spawnAsyncConstrBPHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* wallMarker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* gatehousePreviewMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* randomFormationSocketMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> randomFormationPositions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool writeDebugLogs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> drawDebugFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> disableJobIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> debugLog_AI_general;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> debugLog_AI_tactics;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> debugLog_AI_construction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool shouldUpdateDebugLog_generalAI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool shouldUpdateDebugLog_tacticsAI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool shouldUpdateDebugLog_construction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float gameSpeedScheduled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float gameSpeedBeforePause;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isGameSpeedScheduled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float locomotionTicksAdjusted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float locomotionTicksAdjustedPrevious;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool useLegacyVATM;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EUnitRole, FSoftClassPath> UnitBlueprints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPopupCache> PopupCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSessionAchievementData SessionAchievementData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isNightAndAffectsGameplay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* unitBannerMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* bouncedLightMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UVARuntimeComponent*> birdFlockVARuntimeComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> tutorialsLeftToShow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGood> ForeignMarketSupply;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMBuildingMaster*> landscapeDeformationBuildings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTradeLogEntry> tradeLog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<ASMBuildingMaster*, USphereReflectionCaptureComponent*> reflectionSpheres;
    
    ARTSMultiEngineCPP(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void updateSquadEquipmentStats(const int32& squadID);
    
    UFUNCTION(BlueprintCallable)
    void updateRegionsAndBorders(bool inEditor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void updateRegionNamesTxt();
    
    UFUNCTION(BlueprintCallable)
    void updateProjectileManager();
    
    UFUNCTION(BlueprintCallable)
    void updatePlayerRequests();
    
    UFUNCTION(BlueprintCallable)
    void updateOpenClaims();
    
    UFUNCTION(BlueprintCallable)
    void updateKingsFavourite();
    
    UFUNCTION(BlueprintCallable)
    void updateFreeMerchants();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void updateChallengeStatus(FChallenge& Challenge);
    
    UFUNCTION(BlueprintCallable)
    void updateChallengeDay();
    
    UFUNCTION(BlueprintCallable)
    void updateAllPawnsCommandedSquadsAndEnemies();
    
    UFUNCTION(BlueprintCallable)
    void updateAllPawnsArmies();
    
    UFUNCTION(BlueprintCallable)
    void updateAllChallenges();
    
    UFUNCTION(BlueprintCallable)
    void triggerExampleBattle();
    
    UFUNCTION(BlueprintCallable)
    static bool Triangulate_Process(const TArray<FVector>& contour, TArray<FVector>& Result);
    
    UFUNCTION(BlueprintCallable)
    static bool Triangulate_InsideTriangle(float Ax, float Ay, float bX, float bY, float Cx, float Cy, float Px, float Py);
    
    UFUNCTION(BlueprintCallable)
    static float Triangulate_Area(const TArray<FVector>& contour);
    
    UFUNCTION(BlueprintCallable)
    void triangulate(TArray<FVector>& Vertices, TArray<FTriangle>& outTriangles);
    
    UFUNCTION(BlueprintCallable)
    void splitRoadWithBorder(ARoad* roadToSplit, const TArray<FVector>& fieldPoints);
    
    UFUNCTION(BlueprintCallable)
    void spawnRaiders(const int32 numSquads, const FVector& armyCenter);
    
    UFUNCTION(BlueprintCallable)
    APawnCPP* spawnNewAILord(const FString& lordsName, bool isFemale, UTexture2D* Portrait, bool canBuild);
    
    UFUNCTION(BlueprintCallable)
    void spawnMerchantHerd(ASMUnit* livestockMerchant);
    
    UFUNCTION(BlueprintCallable)
    ASMUnit* spawnLivestockMerchant(ASMBuildingMaster* nearBuilding);
    
    UFUNCTION(BlueprintCallable)
    ASMUnit* SpawnLivestock(EUnitRole AnimalType, const FVector& animalSpawnPos, ARegion* Region);
    
    UFUNCTION(BlueprintCallable)
    ASMUnit* spawnFreeMerchant(ARegion* attachedToRegion);
    
    UFUNCTION(BlueprintCallable)
    void spawnEliteRaiders(const FVector& armyCenter);
    
    UFUNCTION(BlueprintCallable)
    int32 spawnCompleteUnit(const FName& tempName, const FVector& Location, const FRotator& Rotation, APawnCPP* ownerPawn, int32 companyID, int32 arrivesInDays);
    
    UFUNCTION(BlueprintCallable)
    void spawnBloodDecal(const FVector& Position);
    
    UFUNCTION(BlueprintCallable)
    void spawnBanditCamp();
    
    UFUNCTION(BlueprintCallable)
    void spawnAsyncContstrBPLazy();
    
    UFUNCTION(BlueprintCallable)
    TArray<int32> spawnArmy(const FVector& Pos, const TArray<FName>& unitTypes, APawnCPP* ownerPawn, const int32& companyID, const int32& arrivesInDays);
    
    UFUNCTION(BlueprintCallable)
    void snapAngleToNearestRoadIfClose(const FVector& Pos, FRotator& outAngle);
    
    UFUNCTION(BlueprintCallable)
    static void simplifyPolygon(TArray<FVector>& Vertices);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void setupUpgrades();
    
    UFUNCTION(BlueprintCallable)
    void setRegionsManor(ASMBuildingMaster* manor);
    
    UFUNCTION(BlueprintCallable)
    void setDay(int32 day);
    
    UFUNCTION(BlueprintCallable)
    static bool segmentIntersectsSphere(const FVector& A, const FVector& B, const FVector& Origin, float Radius);
    
    UFUNCTION(BlueprintCallable)
    bool segmentCollidesWithAnyBuilding(const FSegment& Segment, const FBox2D& segmentBounds, bool countRoadPointArea);
    
    UFUNCTION(BlueprintCallable)
    void RespawnCameraBasedGroundCover();
    
    UFUNCTION(BlueprintCallable)
    void resetCoreTimers();
    
    UFUNCTION(BlueprintCallable)
    void rerollMercenaries();
    
    UFUNCTION(BlueprintCallable)
    static void removeDuplicateVectors(TArray<FVector>& vecArr, float minDistSq);
    
    UFUNCTION(BlueprintCallable)
    void removeAllPPsCreatedBy(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void removeAllObstaclesCreatedBy(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void removeAllFieldSnapPointsCreatedBy(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void refillMercenaries();
    
    UFUNCTION(BlueprintCallable)
    void redrawForestMask();
    
    UFUNCTION(BlueprintCallable)
    void redrawFertilitySlow();
    
    UFUNCTION(BlueprintCallable)
    void redrawFertilityComplete();
    
    UFUNCTION(BlueprintCallable)
    void RebuildWaterTextures();
    
    UFUNCTION(BlueprintCallable)
    void randomizeRecruitmentPool();
    
    UFUNCTION(BlueprintCallable)
    static void projectCircularBorder(const FVector& Center, float Radius, TArray<FVector>& outSmoothBorder, TArray<FVector>& outBorder);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FVector> projectBorder(FVector2D Dimensions, FTransform Transform);
    
    UFUNCTION(BlueprintCallable)
    bool pointCollidesWithBuildingBorder(const FVector& Point);
    
    UFUNCTION(BlueprintCallable)
    void playResourceFx(int32 Type, bool putdown, const FVector& Pos);
    
    UFUNCTION(BlueprintCallable)
    void playImpact(const int32& Type, const FVector& Location, const FRotator& EmitterRotation, const bool& particleEffect, const float& volumeMul);
    
    UFUNCTION(BlueprintCallable)
    void playAmbientVoice();
    
    UFUNCTION(BlueprintCallable)
    void placeSnowStep(const FVector& Pos);
    
    UFUNCTION(BlueprintCallable)
    void pickNewLeader(int32 squadID);
    
    UFUNCTION(BlueprintCallable)
    FVector pickNearestPos(const FVector& Pos, const TArray<FVector>& Options);
    
    UFUNCTION(BlueprintCallable)
    float pairToFloat(const FVector2D& P);
    
    UFUNCTION(BlueprintCallable)
    static float onTheSameSide(FVector P, FVector Q, FVector A, FVector B);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnParticleSystemFinished(UParticleSystemComponent* ps);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isResourceFood(const int32& resourceType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMinorTrade(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isHarvestSeason();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isBuildingTypeValid(int32 buildingID);
    
    UFUNCTION(BlueprintCallable)
    uint8 isAreaObstructedByUnits(const FVector& Pos, const float radiusSq, ASMUnit* outUnit);
    
    UFUNCTION(BlueprintCallable)
    bool intersectTwoComplexBorders(const TArray<FVector>& borderA, const TArray<FVector>& borderB, FVector& Out);
    
    UFUNCTION(BlueprintCallable)
    bool intersectRoads(const FVector& A, const FVector& B, const bool& Center, FVector& Out, bool simple, const FBox2D& segmentBounds);
    
    UFUNCTION(BlueprintCallable)
    bool intersectComplexBorders(const FBBorder& borderA, const TArray<FVector> borderB, FVector& Out);
    
    UFUNCTION(BlueprintCallable)
    bool intersectBorders(const FBBorder& borderA, const FBBorder& borderB, FVector& Out);
    
    UFUNCTION(BlueprintCallable)
    void initChallenge(APawnCPP* challengedPawn, APawnCPP* challengedBy, ARegion* Region);
    
    UFUNCTION(BlueprintCallable)
    TArray<int32> hireMercs(FMercenaryCompany company, APawnCPP* pawnRef);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getWindTimeAdjusted();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector4 getWeatherDetails();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FUpgrade getUpgradeData(int32 upgradeID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FColor getUnusedPlayerColor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getTradeValue(ARegion* Region, const FName& Filter, int32 startDay, int32 endDay);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FTradeLogEntry> getTradeLogSummedTradedGoods(ARegion* Region, int32 startDay, int32 endDay);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FTradeLogEntry> getTradeLogAllTradedGoods(ARegion* Region, int32 startDay, int32 endDay);
    
    UFUNCTION(BlueprintCallable)
    static float getSegmentToBorderParallelFactor(const FSegment& Segment, const TArray<FVector>& SmoothBorder, bool accountForDistance);
    
    UFUNCTION(BlueprintCallable)
    TSubclassOf<AResource> getResourceBP(const FName& resType);
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool getRelationTags(const APawnCPP*& pawnA, const APawnCPP*& pawnB, TArray<FName>& relationTags);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 getRegionIndex(ARegion* Region);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARegion* getRegionFromIndex(uint8 regionIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARegion* getRegionByPos(const FVector& Pos, bool skipBoundCheck) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void getRandomSquad(FSquad& newSquad);
    
    UFUNCTION(BlueprintCallable)
    int32 getRandomPeasantClothes();
    
    UFUNCTION(BlueprintCallable)
    float getRandomObstructionYaw();
    
    UFUNCTION(BlueprintCallable)
    float getRandomObstructionForce();
    
    UFUNCTION(BlueprintCallable)
    int32 getRandomHead(bool isWoman, bool combat);
    
    UFUNCTION(BlueprintCallable)
    int32 getRandomHat(bool isWoman, bool isBurgher);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getPriceOfGood(ARegion* Region, int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getPreviousMonthStartDay();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getPreviousMonthEndDay();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APawnCPP* getPawnBySetupIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    float getPathPrice(const FVector& A, const FVector& B);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getNearestUnobstructedMapEdgePos(const FVector& nearPos, float boundExtents);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getNearestMapEdgePos(const FVector& nearPos, bool openOnly);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLorePoint getNearestLorePoint();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ASMBuildingMaster* getNearestBuildingTo(const FVector& Location, TArray<ASMBuildingMaster*> buildingsToCheck);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getMonthsTotal();
    
    UFUNCTION(BlueprintCallable)
    float getModuleRadiusForBuildingID(int32 buildingID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getLowestImportPrice(ARegion* Region, int32 goodType, bool ignoreTradeRouteRequirements);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void getLoadedConstructionTemplate(const TSoftClassPtr<AConstruction>& constructionAsset, TSubclassOf<AConstruction>& outConstructionTemplate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FItem getItem(const int32 ItemId);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FPair getImportPriceRange(ARegion* Region, int32 goodType, bool& OutMayIncludeTariff, bool ignoreTradeRouteRequirements);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<int32> GetGoodTypesInSubcategory(EItemSubcategory Subcategory);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getGlobalDemandPriceMultiplierForGood(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getGameTimeAdjusted();
    
    UFUNCTION(BlueprintCallable)
    FVector getFieldDominatingAngle(const TArray<FVector>& fieldBorderPoints);
    
    UFUNCTION(BlueprintCallable)
    int32 getFertilityIDandPos(const FVector& Pos, int32& outX, int32& outY);
    
    UFUNCTION(BlueprintCallable)
    int32 getFertilityID(const FVector& Pos);
    
    UFUNCTION(BlueprintCallable)
    float getFertilityAtGridID(int32 GridId, ECropType cropType);
    
    UFUNCTION(BlueprintCallable)
    float getFertility(const FVector& Pos, ECropType cropType);
    
    UFUNCTION(BlueprintCallable)
    void getFarmingInfo(ASMBuildingMaster* building, bool& isPlowing, bool& allPlowed, bool& allHarvested);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UStaticMesh* getFallenTreeMeshForTree(const UStaticMesh* treeMesh, FString& stumpName);
    
    UFUNCTION(BlueprintCallable)
    static float getDistanceSquaredBetweenSmoothSegments(const TArray<FVector>& smoothA, const TArray<FVector>& smoothB);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FEquipment getDefaultMilitiaEquipmentForUnitTemplate(const FName& TemplateName);
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDefaultApprovalRateForFactor(const EApprovalFactorType Type) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FVector> getDeerLairLocations();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getDaysTotal();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getDayOfTheYear();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getCurrentMonth();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void getConstructionBP(const int32& HISM, TSubclassOf<AConstruction>& ConstructionBP);
    
    UFUNCTION(BlueprintCallable)
    FSoftObjectPath getBuildingPartMeshPath(int32 iType);
    
    UFUNCTION(BlueprintCallable)
    float getBuildingInternalOffsetFromWall(int32 bType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FStat getBuildingData(int32 buildingID);
    
    UFUNCTION(BlueprintCallable)
    ASMBuildingMaster* getBuildingByID(int32& UniqueID);
    
    UFUNCTION(BlueprintCallable)
    static float getBorderLength(const TArray<FVector>& fieldPoints);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FUnitStat getAverageUnitStat(const FName& Temp);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FUnitStat getAverageEquipmentStat(const TArray<int32>& equipmentItems);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getAvailableExportPrice(ARegion* Region, int32 goodType, bool bIgnoreTradeRestrictions);
    
    UFUNCTION(BlueprintCallable)
    UDataTable* getAnimsetDataTable(const FName SetName);
    
    UFUNCTION(BlueprintCallable)
    FName getAnimNameForAnimID(int32 animID, UDataTable* AnimSet, int32 variationID);
    
    UFUNCTION(BlueprintCallable)
    EUnitRole getAnimalRoleFromGoodType(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FTradeLogEntry> getAllTradeLogEntriesForRegion(ARegion* Region);
    
    UFUNCTION(BlueprintCallable)
    void generateFertilityValues();
    
    UFUNCTION(BlueprintCallable)
    void fulfillKingsFavour();
    
    UFUNCTION(BlueprintCallable)
    static bool fitModuleTransformAlongBorder(const TArray<FVector>& targetBorderPoints, const TArray<FVector>& boundaryAreaPoints, float initialDistanceOffset, float moduleWidthHalf, float moduleHeightHalf, FTransform& OutTransform, float collisionDistanceIncrementValue, int32 maxAttempts, TArray<FVector> extraCollisionBorder);
    
    UFUNCTION(BlueprintCallable)
    void finishSpawningSoloBuildingAsync(FBuildingSpawnParams Params);
    
    UFUNCTION(BlueprintCallable)
    AUnitSpawner* findUnitSpawnerWithTag(const FName& Tag);
    
    UFUNCTION(BlueprintCallable)
    ASMUnit* findUnitByPos(const FVector& Pos);
    
    UFUNCTION(BlueprintCallable)
    AResource* findResourceByPos(const FVector& Pos);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARegion* findRegionByName(const FString& Name);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARegion* findRegionByID(const int32& regionID);
    
    UFUNCTION(BlueprintCallable)
    int32 findLinkIDByPos(const FVector& Pos);
    
    UFUNCTION(BlueprintCallable)
    FVector findGoodSquadMoveTargetNear(const FVector& Location);
    
    UFUNCTION(BlueprintCallable)
    void finalizeChallenge(FChallenge& Challenge, APawnCPP* victoriousPawn);
    
    UFUNCTION(BlueprintCallable)
    static int32 extractBTypeFromTag(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static int32 extractBTypeFromComponentTag(const UStaticMeshComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void eraseBuildingReferences(ASMBuildingMaster* building);
    
    UFUNCTION(BlueprintCallable)
    void eraseArmy(FArmy Army);
    
    UFUNCTION(BlueprintCallable)
    static bool doTwoSmoothBordersIntersect(const TArray<FVector>& borderA, const TArray<FVector>& borderB);
    
    UFUNCTION(BlueprintCallable)
    bool doesTriangulatedBorderCollideWithOneOfTheRoads(const FBox2D& bounds2d, const TArray<FVector>& triangulatedBorder, const TArray<ARoad*> roadsToCheck);
    
    UFUNCTION(BlueprintCallable)
    bool doesTriangulatedBorderCollideWithAnyRoad(TArray<FVector>& Border, TArray<FVector>& triangulatedBorder, const FVector& Center);
    
    UFUNCTION(BlueprintCallable)
    bool doesSegmentOverlapComplexBorder(const FSegment& Segment, const TArray<FVector>& Border, const TArray<FVector>& triangulated);
    
    UFUNCTION(BlueprintCallable)
    bool doesSegmentIntersectRectangle(const FSegment2D& Segment, const FBox2D& rect);
    
    UFUNCTION(BlueprintCallable)
    void destroyUnit(ASMUnit* unit);
    
    UFUNCTION(BlueprintCallable)
    void clampFertilityValuesForDirtyCells();
    
    UFUNCTION(BlueprintCallable)
    static bool checkPointWithinComplexBorder(const FVector& Point, const TArray<FVector>& Points, const FVector& Center);
    
    UFUNCTION(BlueprintCallable)
    void changeFertilityCellUnclamped(int32 CellID, int32 cropType, float change);
    
    UFUNCTION(BlueprintCallable)
    void changeFertilityCell(int32 CellID, int32 cropType, float change);
    
    UFUNCTION(BlueprintCallable)
    void changeFertility(const FVector& Pos, int32 cropType, float change);
    
    UFUNCTION(BlueprintCallable)
    float calculateWindmillEfficiency(const FVector& Pos);
    
    UFUNCTION(BlueprintCallable)
    bool breedAnimal(ASMUnit* father);
    
    UFUNCTION(BlueprintCallable)
    bool anyCivInRange(const FVector& Pos, const float& rangeSq, bool& isBuilding);
    
    UFUNCTION(BlueprintCallable)
    static void alignToGroundQuatFast(UPARAM(Ref) FQuat& worldRotation, const FVector& groundNormal);
    
    UFUNCTION(BlueprintCallable)
    static void alignRotationToGround(UPARAM(Ref) FRotator& worldRotation, const FVector& groundNormal);
    
    UFUNCTION(BlueprintCallable)
    bool addRelationTag(APawnCPP* pawnA, APawnCPP* pawnB, FName newTag);
    
    UFUNCTION(BlueprintCallable)
    void addPawnRelations(APawnCPP* pawnA);
    
    UFUNCTION(BlueprintCallable)
    void AddCliffCollision();
    
};

