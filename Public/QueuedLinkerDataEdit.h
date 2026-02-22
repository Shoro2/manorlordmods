#pragma once
#include "CoreMinimal.h"
#include "EQueuedEditType.h"
#include "QueuedLinkerDataEdit.generated.h"

USTRUCT(BlueprintType)
struct FQueuedLinkerDataEdit {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EQueuedEditType editType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 mainThreadArrayOffset;
    
    MANORLORDS_API FQueuedLinkerDataEdit();
};

