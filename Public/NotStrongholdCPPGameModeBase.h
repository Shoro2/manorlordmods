#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=GameModeBase -FallbackName=GameModeBase
#include "NotStrongholdCPPGameModeBase.generated.h"

UCLASS(Blueprintable, NonTransient)
class MANORLORDS_API ANotStrongholdCPPGameModeBase : public AGameModeBase {
    GENERATED_BODY()
public:
    ANotStrongholdCPPGameModeBase(const FObjectInitializer& ObjectInitializer);

};

