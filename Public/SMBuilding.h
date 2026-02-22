#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshActor -FallbackName=StaticMeshActor
#include "SMBuilding.generated.h"

class ASMBuildingMaster;
class UGateComponent;

UCLASS(Blueprintable)
class MANORLORDS_API ASMBuilding : public AStaticMeshActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* buildingMaster;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGateComponent* controllableGate;
    
    ASMBuilding(const FObjectInitializer& ObjectInitializer);

};

