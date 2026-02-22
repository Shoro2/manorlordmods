#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=SystemCore -ObjectName=EInputIconButton -FallbackName=EInputIconButton
//CROSS-MODULE INCLUDE V2: -ModuleName=SystemCore -ObjectName=ENaviUiIntent -FallbackName=ENaviUiIntent
#include "ControlHookConfig.h"
#include "ControlHookFlow.h"
#include "ControlHookState.h"
#include "OnControlHookInputModeChangeDelegate.h"
#include "OnControlHookUiHasPriorityDelegate.h"
#include "ControlHook.generated.h"

class UNaviUi;
class UTexture2D;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MANORLORDS_API UControlHook : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FControlHookConfig Config;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FControlHookState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FControlHookFlow controlFlow;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnControlHookInputModeChange OnInputModeChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnControlHookUiHasPriority OnUiHasPriorityChange;
    
    UControlHook(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool ShowControllerCursors();
    
    UFUNCTION(BlueprintCallable)
    void SetInPriorityWindow(bool inPriorityWindow);
    
    UFUNCTION(BlueprintCallable)
    void SetFlowInTutorial(bool inTutorial);
    
    UFUNCTION(BlueprintCallable)
    void SetFlowInFullscreen(bool inFullscreen);
    
    UFUNCTION(BlueprintCallable)
    void SetFlowInExplore(bool inExplore);
    
    UFUNCTION(BlueprintCallable)
    void SetFlow(FControlHookFlow newFlow);
    
    UFUNCTION(BlueprintCallable)
    void SendMouseToCenter();
    
    UFUNCTION(BlueprintCallable)
    void SendInput(ENaviUiIntent intent);
    
    UFUNCTION(BlueprintCallable)
    void SendAcceptToTool();
    
    UFUNCTION(BlueprintCallable)
    static UTexture2D* GetInputIcon(EInputIconButton Button);
    
    UFUNCTION(BlueprintCallable)
    FControlHookFlow GetFlow();
    
    UFUNCTION(BlueprintCallable)
    void BindActiveUi(UNaviUi* rootUi, bool isPureUi);
    
};

