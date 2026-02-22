#pragma once
#include "CoreMinimal.h"
#include "SavedRelationsTag.generated.h"

USTRUCT(BlueprintType)
struct FSavedRelationsTag {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 pawnA_setupIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 pawnB_setupIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Tag;
    
    MANORLORDS_API FSavedRelationsTag();
};

