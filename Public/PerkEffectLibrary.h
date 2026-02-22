#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=WidgetBlueprintLibrary -FallbackName=WidgetBlueprintLibrary
#include "EPerkEffect.h"
#include "PerkEffectLibrary.generated.h"

UCLASS(Blueprintable)
class MANORLORDS_API UPerkEffectLibrary : public UWidgetBlueprintLibrary {
    GENERATED_BODY()
public:
    UPerkEffectLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPerkEffectNegative(EPerkEffect PerkEffet);
    
};

