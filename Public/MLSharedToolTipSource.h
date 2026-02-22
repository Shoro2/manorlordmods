#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include "MLSharedToolTipSource.generated.h"

class UUserWidget;

UINTERFACE(Blueprintable)
class UMLSharedToolTipSource : public UInterface {
    GENERATED_BODY()
};

class IMLSharedToolTipSource : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ResetToolTip(UUserWidget* InToolTip);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitToolTip(UUserWidget* InToolTip);
    
};

