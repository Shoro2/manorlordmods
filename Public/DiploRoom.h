#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "DiploRoom.generated.h"

UCLASS(Blueprintable)
class MANORLORDS_API ADiploRoom : public AActor {
    GENERATED_BODY()
public:
    ADiploRoom(const FObjectInitializer& ObjectInitializer);

};

