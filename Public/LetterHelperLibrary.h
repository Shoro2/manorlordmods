#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "LetterHelperLibrary.generated.h"

UCLASS(Blueprintable)
class ULetterHelperLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    ULetterHelperLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 getLetterCost(const TArray<FName>& Letter);
    
};

