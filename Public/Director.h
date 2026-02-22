#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "Reward.h"
#include "Director.generated.h"

class APawnCPP;
class ARegion;
class UDataTable;

UCLASS(Blueprintable)
class MANORLORDS_API ADirector : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_Quests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> issuedQuests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 scenario_nextActionDay;
    
    ADirector(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    bool startQuestFromPreset(const FName& questTag, APawnCPP* questPawn, TArray<FReward> extraRewards, ARegion* questRegion, bool askFirst, int32 daysLeftOverride);
    
};

