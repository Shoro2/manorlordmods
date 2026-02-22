#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "AffinityComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MANORLORDS_API UAffinityComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UAffinityComponent(const FObjectInitializer& ObjectInitializer);

};

