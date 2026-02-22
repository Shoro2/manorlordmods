#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Pawn -FallbackName=Pawn
#include "MenuPawn.generated.h"

UCLASS(Blueprintable)
class MANORLORDS_API AMenuPawn : public APawn {
    GENERATED_BODY()
public:
    AMenuPawn(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnWindowFocusChanged(bool bIsFocused);
    
};

