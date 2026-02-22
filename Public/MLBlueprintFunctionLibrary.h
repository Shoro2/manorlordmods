#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "Good.h"
#include "Quest.h"
#include "MLBlueprintFunctionLibrary.generated.h"

class AActor;
class ARegion;
class UUserWidget;

UCLASS(Blueprintable)
class MANORLORDS_API UMLBlueprintFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMLBlueprintFunctionLibrary();

    UFUNCTION(BlueprintCallable)
    static void setQuestRegion(UPARAM(Ref) FQuest& Quest, ARegion* Region);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool inventoryHasGoodType(const TArray<FGood>& Inventory, int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 getStockOfGood(const TArray<FGood>& Inventory, int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<int32> getSpecialReserveGoodTypes();
    
    UFUNCTION(BlueprintCallable)
    static FVector2D GetAbsolutePosition(UUserWidget* Widget);
    
    UFUNCTION(BlueprintCallable)
    static int32 extractBTypeFromActorTag(const AActor* Actor);
    
};

