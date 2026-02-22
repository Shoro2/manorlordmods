#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=VertexAnimationManager -ObjectName=VAISMController -FallbackName=VAISMController
#include "VAISMExtra.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MANORLORDS_API UVAISMExtra : public UVAISMController {
    GENERATED_BODY()
public:
    UVAISMExtra(const FObjectInitializer& ObjectInitializer);

};

