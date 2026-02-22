#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "Obstacle.generated.h"

UCLASS(Blueprintable)
class MANORLORDS_API AObstacle : public AActor {
    GENERATED_BODY()
public:
    AObstacle(const FObjectInitializer& ObjectInitializer);

};

