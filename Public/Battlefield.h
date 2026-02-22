#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "Battlefield.generated.h"

class ARTSMultiEngineCPP;

UCLASS(Blueprintable)
class MANORLORDS_API ABattlefield : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARTSMultiEngineCPP* masterPtr;
    
    ABattlefield(const FObjectInitializer& ObjectInitializer);

};

