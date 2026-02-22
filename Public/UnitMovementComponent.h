#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "UnitMovementComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MANORLORDS_API UUnitMovementComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UUnitMovementComponent(const FObjectInitializer& ObjectInitializer);

};

