#include "MLBlueprintFunctionLibrary.h"

UMLBlueprintFunctionLibrary::UMLBlueprintFunctionLibrary() {
}

void UMLBlueprintFunctionLibrary::setQuestRegion(FQuest& Quest, ARegion* Region) {
}

bool UMLBlueprintFunctionLibrary::inventoryHasGoodType(const TArray<FGood>& Inventory, int32 goodType) {
    return false;
}

int32 UMLBlueprintFunctionLibrary::getStockOfGood(const TArray<FGood>& Inventory, int32 goodType) {
    return 0;
}

TArray<int32> UMLBlueprintFunctionLibrary::getSpecialReserveGoodTypes() {
    return TArray<int32>();
}

FVector2D UMLBlueprintFunctionLibrary::GetAbsolutePosition(UUserWidget* Widget) {
    return FVector2D{};
}

int32 UMLBlueprintFunctionLibrary::extractBTypeFromActorTag(const AActor* Actor) {
    return 0;
}


