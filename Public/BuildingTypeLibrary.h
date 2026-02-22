#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=WidgetBlueprintLibrary -FallbackName=WidgetBlueprintLibrary
#include "BuildingTypeLibrary.generated.h"

class ASMBuildingMaster;

UCLASS(Blueprintable)
class MANORLORDS_API UBuildingTypeLibrary : public UWidgetBlueprintLibrary {
    GENERATED_BODY()
public:
    UBuildingTypeLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasYearlyYield(ASMBuildingMaster* InBuildingMaster);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool CanCauseDeforestation(int32 InBuildingType);
    
};

