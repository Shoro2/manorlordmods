#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=DeveloperSettings -ObjectName=DeveloperSettings -FallbackName=DeveloperSettings
#include "ENodeType.h"
#include "ResourceNodeData.h"
#include "ResourceNodeProperties.h"
#include "ResourceSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UResourceSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float startleDistance;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float resourceDepositRadius;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float resourceRichDepositRadius;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MapDecalWorldSize;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MapDecalWorldSizeRich;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ElevationPercentage;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ElevationDeathPercentage;
    
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ENodeType> MineableNodes;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FResourceNodeData> ResourceNodeData;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ResourceClumpCollisionRadius;
    
    UResourceSettings();

    UFUNCTION(BlueprintPure)
    FResourceNodeProperties GetPropertiesForType(ENodeType Type) const;
    
};

