#pragma once
#include "CoreMinimal.h"
#include "SavedGood.generated.h"

USTRUCT(BlueprintType)
struct FSavedGood {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 amt;
    
    MANORLORDS_API FSavedGood();
};

