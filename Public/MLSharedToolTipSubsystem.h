#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=LocalPlayerSubsystem -FallbackName=LocalPlayerSubsystem
#include "Templates/SubclassOf.h"
#include "MLSharedToolTipSubsystem.generated.h"

class UUserWidget;

UCLASS(Blueprintable)
class UMLSharedToolTipSubsystem : public ULocalPlayerSubsystem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TMap<UClass*, UUserWidget*> SharedToolTips;
    
public:
    UMLSharedToolTipSubsystem();

    UFUNCTION(BlueprintCallable)
    static UUserWidget* SetSharedToolTip(UUserWidget* InForWidget, TSubclassOf<UUserWidget> ToolTipClass);
    
};

