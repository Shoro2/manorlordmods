#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Water -ObjectName=WaterBodyRiver -FallbackName=WaterBodyRiver
#include "MLWaterBodyRiver.generated.h"

UCLASS(Blueprintable)
class MANORLORDS_API AMLWaterBodyRiver : public AWaterBodyRiver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGenerateCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BankCollisionOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SubdivisionTargetLength;
    
    AMLWaterBodyRiver(const FObjectInitializer& ObjectInitializer);

};

