#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "HudIconData.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FHudIconData : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* iconTexture;
    
    MANORLORDS_API FHudIconData();
};

