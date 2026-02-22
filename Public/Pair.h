#pragma once
#include "CoreMinimal.h"
#include "Pair.generated.h"

USTRUCT(BlueprintType)
struct FPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    MANORLORDS_API FPair();
};

