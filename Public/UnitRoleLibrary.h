#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=WidgetBlueprintLibrary -FallbackName=WidgetBlueprintLibrary
#include "EUnitRole.h"
#include "UnitRoleLibrary.generated.h"

UCLASS(Blueprintable)
class MANORLORDS_API UUnitRoleLibrary : public UWidgetBlueprintLibrary {
    GENERATED_BODY()
public:
    UUnitRoleLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsWildAnimal(EUnitRole unitRole);
    
};

