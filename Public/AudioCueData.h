#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "AudioCueData.generated.h"

class USoundBase;

USTRUCT(BlueprintType)
struct FAudioCueData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* audioCue;
    
    MANORLORDS_API FAudioCueData();
};

