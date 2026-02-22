#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=WidgetBlueprintLibrary -FallbackName=WidgetBlueprintLibrary
#include "EAffinityType.h"
#include "EMaintenanceEffect.h"
#include "MLWidgetBlueprintLibrary.generated.h"

class UMLSaveGameDescr;

UCLASS(Blueprintable)
class MANORLORDS_API UMLWidgetBlueprintLibrary : public UWidgetBlueprintLibrary {
    GENERATED_BODY()
public:
    UMLWidgetBlueprintLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText KfyNumber(int32 Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSaveDeprecated(const UMLSaveGameDescr* InDesc);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetRawEnumName_MaintenanceEffect(const EMaintenanceEffect Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetRawEnumName(const EAffinityType Affinity);
    
};

