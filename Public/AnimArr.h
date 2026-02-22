#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "AnimStruct.h"
#include "AnimArr.generated.h"

USTRUCT(BlueprintType)
struct FAnimArr : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimStruct> anims;
    
    MANORLORDS_API FAnimArr();
};

