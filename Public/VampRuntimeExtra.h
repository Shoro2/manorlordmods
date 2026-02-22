#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=VertexAnimationManager -ObjectName=VARuntimeComponent -FallbackName=VARuntimeComponent
#include "VampRuntimeExtra.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MANORLORDS_API UVampRuntimeExtra : public UVARuntimeComponent {
    GENERATED_BODY()
public:
    UVampRuntimeExtra(const FObjectInitializer& ObjectInitializer);

};

