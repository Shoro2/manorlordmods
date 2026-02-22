#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=UserWidget -FallbackName=UserWidget
#include "Good.h"
#include "RegionProductionStockEntry.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URegionProductionStockEntry : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGood Good;
    
    URegionProductionStockEntry();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateDelta(const int32 InDelta, const int32 InTotal, const int32 InProduced, const int32 InConsumed);
    
    UFUNCTION(BlueprintCallable)
    void ReportTrackingChanged(const bool InNewTrackedState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitialiseFromGood(const FGood& InGood, const bool InIsTracked);
    
};

