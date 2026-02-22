#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "EPerkEffect.h"
#include "PerkHelperLibrary.generated.h"

class IRegionProviderInterface;
class URegionProviderInterface;

UCLASS(Blueprintable)
class UPerkHelperLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UPerkHelperLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsEffectActive(const TScriptInterface<IRegionProviderInterface>& InRegionProvider, const EPerkEffect InPerkToQuery);
    
};

