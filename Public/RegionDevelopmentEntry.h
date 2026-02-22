#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=UserWidget -FallbackName=UserWidget
#include "OnDevelopmentEntrySelectedDelegate.h"
#include "RegionDevelopmentEntry.generated.h"

class UButton;

UCLASS(Blueprintable, EditInlineNew)
class URegionDevelopmentEntry : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SettlementLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButton* SelectButton;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDevelopmentEntrySelected OnSelectedSig;
    
    URegionDevelopmentEntry();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateLockedState(const int32 InCurrentRegionSettlementLevel);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSelected();
    
};

