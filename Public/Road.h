#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ERuntimeVirtualTextureMainPassType -FallbackName=ERuntimeVirtualTextureMainPassType
#include "EPlatformLevel.h"
#include "ERoadType.h"
#include "EWallType.h"
#include "Good.h"
#include "Segment.h"
#include "Road.generated.h"

class ARTSMultiEngineCPP;
class ARegion;
class ASMBuildingMaster;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class URuntimeVirtualTexture;
class USplineComponent;
class USplineMeshComponent;
class UStaticMesh;
class UStaticMeshComponent;
class UTexture2D;

UCLASS(Blueprintable)
class MANORLORDS_API ARoad : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARTSMultiEngineCPP* masterPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool kingsRoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isBlueprint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERoadType roadType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWallType wallType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPlatformLevel platformLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float roadTangentScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* Spline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USplineMeshComponent*> SplineMeshComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> StaticMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float roadWidth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float spacing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* roadMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSegment> unadjustedMeshLocations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool resampled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SplineSimplification_MinDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SplineSimplification_AngleThresholdDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* MaterialOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* guideMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* guideMatBridge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* roadMat_start;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* roadMat_end;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* roadMat_short;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* borderMat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* roadMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARegion* regionA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARegion* regionB;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* MI_Border;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMBuildingMaster*> connectedMarkets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool marketRoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> FoliageComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isBorder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMapEdge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOpenBorder;
    
    ARoad(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void updateForks(bool twoWayConnections);
    
    UFUNCTION(BlueprintCallable)
    void updateBorderMaterials(bool hoveringA, bool hoveringB, bool selectedA, bool selectedB);
    
    UFUNCTION(BlueprintCallable)
    void spawnRoadMeshes();
    
    UFUNCTION(BlueprintCallable)
    UStaticMeshComponent* spawnFoliageComponent(const FVector& Pos, UStaticMesh* StaticMesh);
    
    UFUNCTION(BlueprintCallable)
    void snapSplineToMapEdge(float snapThresholdSq);
    
    UFUNCTION(BlueprintCallable)
    void SimplifySpline();
    
    UFUNCTION(BlueprintCallable)
    void setRVTMode(ERuntimeVirtualTextureMainPassType NewMode);
    
    UFUNCTION(BlueprintCallable)
    void setCommit(const bool& isCommiting);
    
    UFUNCTION(BlueprintCallable)
    bool intersectRoadCached(const FVector& Start, const FVector& End, FVector& Out, const bool& Center, const bool& simple);
    
    UFUNCTION(BlueprintCallable)
    bool insertPointOnSegmentIfPlazaFound(const int32& SplinePoint, FVector& outPos);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FGood> getConstructionCost();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getCachedCenter();
    
    UFUNCTION(BlueprintCallable)
    TArray<ASMBuildingMaster*> getBuildingsNearRoadQuick(const float& distSq);
    
    UFUNCTION(BlueprintCallable)
    void fixBorderRegions();
    
    UFUNCTION(BlueprintCallable)
    void eraseVegetation();
    
    UFUNCTION(BlueprintCallable)
    void connectCachedToPathfinding();
    
    UFUNCTION(BlueprintCallable)
    void clearRoad();
    
    UFUNCTION(BlueprintCallable)
    void cleanSplineMeshes();
    
    UFUNCTION(BlueprintCallable)
    void adjustHeight(const bool inEditor);
    
    UFUNCTION(BlueprintCallable)
    void addRuntimeVirtualTexture(URuntimeVirtualTexture* newRVT, ERuntimeVirtualTextureMainPassType passType);
    
    UFUNCTION(BlueprintCallable)
    void addFieldSnapPoints();
    
};

