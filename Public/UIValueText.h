#pragma once
#include "CoreMinimal.h"
#include "UIValueText.generated.h"

class UTextBlock;

USTRUCT(BlueprintType)
struct FUIValueText {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlock* TextBlock;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlock* TextBlockAlt;
    
    MANORLORDS_API FUIValueText();
};

