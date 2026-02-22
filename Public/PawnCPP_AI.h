#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
#include "PawnCPP.h"
#include "PawnCPP_AI.generated.h"

UCLASS(Blueprintable)
class MANORLORDS_API APawnCPP_AI : public APawnCPP {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle AICommandHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle aiActionHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle AILetterwritingHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDrawDebug;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AI_general_cycles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AI_tactics_cycles;
    
    APawnCPP_AI(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void startAI(float Speed, bool canBuild);
    
    UFUNCTION(BlueprintCallable)
    void RecalculateOptionsDebug();
    
    UFUNCTION(BlueprintCallable)
    void PickBestOptionDebug();
    
};

