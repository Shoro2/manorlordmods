#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "EventWheel.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UEventWheel : public UActorComponent {
    GENERATED_BODY()
public:
    UEventWheel(const FObjectInitializer& ObjectInitializer);

};

