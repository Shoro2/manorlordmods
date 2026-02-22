#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "AnimVariation.h"
#include "UnitAnimset.generated.h"

USTRUCT(BlueprintType)
struct FUnitAnimset : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimVariation> anims;
    
    MANORLORDS_API FUnitAnimset();
};

