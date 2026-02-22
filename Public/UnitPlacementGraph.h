#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "UnitPlacementGraph.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MANORLORDS_API UUnitPlacementGraph : public UActorComponent {
    GENERATED_BODY()
public:
    UUnitPlacementGraph(const FObjectInitializer& ObjectInitializer);

};

