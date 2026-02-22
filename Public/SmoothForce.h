#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "SmoothForce.generated.h"

class ASMUnit;

UCLASS(Blueprintable)
class MANORLORDS_API ASmoothForce : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> affectedUnits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> sorted;
    
    ASmoothForce(const FObjectInitializer& ObjectInitializer);

};

