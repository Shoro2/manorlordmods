#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=UserWidget -FallbackName=UserWidget
#include "Good.h"
#include "LogDate.h"
#include "ProductionPanelTooltip.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UProductionPanelTooltip : public UUserWidget {
    GENERATED_BODY()
public:
    UProductionPanelTooltip();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitFromStockCount(const FLogDate& InDate, const TArray<FGood>& InStock);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitFromEntry(const FLogDate& InDate, const TArray<FGood>& InProduction, const TArray<FGood>& InConsumption);
    
};

