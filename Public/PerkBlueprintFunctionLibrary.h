#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "PerkBlueprintFunctionLibrary.generated.h"

class UDataTable;

UCLASS(Blueprintable)
class MANORLORDS_API UPerkBlueprintFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UPerkBlueprintFunctionLibrary();

    UFUNCTION(BlueprintCallable)
    static FString tryGetPerkNameFromYieldModifier(UDataTable* perkTable, const FString& modifierName);
    
};

