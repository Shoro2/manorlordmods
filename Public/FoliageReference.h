#pragma once
#include "CoreMinimal.h"
#include "FoliageReference.generated.h"

class UInstancedStaticMeshComponent;

USTRUCT(BlueprintType)
struct FFoliageReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* foliageComponent;
    
    MANORLORDS_API FFoliageReference();
};

