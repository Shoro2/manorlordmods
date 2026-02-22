#pragma once
#include "CoreMinimal.h"
#include "Order.generated.h"

USTRUCT(BlueprintType)
struct FOrder {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float progress;
    
    MANORLORDS_API FOrder();
};

