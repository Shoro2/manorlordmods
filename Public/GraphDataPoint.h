#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=UserWidget -FallbackName=UserWidget
#include "Good.h"
#include "GraphDataPoint.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UGraphDataPoint : public UUserWidget {
    GENERATED_BODY()
public:
    UGraphDataPoint();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitFromGoods(const TArray<FGood>& InGoods, const FLinearColor& InColour);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitFromGood(const FGood& InGood, const FLinearColor& InColour);
    
};

