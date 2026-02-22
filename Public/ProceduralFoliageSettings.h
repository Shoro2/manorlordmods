#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=DeveloperSettings -ObjectName=DeveloperSettings -FallbackName=DeveloperSettings
#include "ProceduralGroundCoverData.h"
#include "ProceduralFoliageSettings.generated.h"

class UStaticMesh;

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UProceduralFoliageSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FProceduralGroundCoverData> proceduralGroundCoverTypes;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> groundCoverDistributionSocketMesh;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 numberOfCameraGroundCoverCellColumnsHalf;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float cameraBasedGroundCoverCellSize;
    
    UProceduralFoliageSettings();

};

