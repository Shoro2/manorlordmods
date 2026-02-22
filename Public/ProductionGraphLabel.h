#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=UserWidget -FallbackName=UserWidget
#include "ProductionGraphLabel.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UProductionGraphLabel : public UUserWidget {
    GENERATED_BODY()
public:
    UProductionGraphLabel();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitFromText(const FText& InText);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitFromDate(const int32 InDay, const int32 InMonth, const int32 InYear);
    
};

