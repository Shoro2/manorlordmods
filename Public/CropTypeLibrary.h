#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=WidgetBlueprintLibrary -FallbackName=WidgetBlueprintLibrary
#include "ECropType.h"
#include "CropTypeLibrary.generated.h"

UCLASS(Blueprintable)
class MANORLORDS_API UCropTypeLibrary : public UWidgetBlueprintLibrary {
    GENERATED_BODY()
public:
    UCropTypeLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool NeedsAlmostFullGrowthBeforeHarvest(ECropType Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsVegetableCropType(ECropType Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsFruitCropType(ECropType Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsFertilityBased(ECropType Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsBackyardCrop(ECropType Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetItemIDFromCropType(ECropType Type);
    
};

