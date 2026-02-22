#pragma once
#include "CoreMinimal.h"
#include "DefferedMeshLoadItem.generated.h"

class UHierarchicalInstancedStaticMeshComponent;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FDefferedMeshLoadItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHierarchicalInstancedStaticMeshComponent* HISM;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 iType;
    
    MANORLORDS_API FDefferedMeshLoadItem();
};

