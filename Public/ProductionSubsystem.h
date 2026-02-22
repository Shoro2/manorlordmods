#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=WorldSubsystem -FallbackName=WorldSubsystem
#include "ProductionSubsystem.generated.h"

class ARegion;

UCLASS(Blueprintable)
class UProductionSubsystem : public UWorldSubsystem {
    GENERATED_BODY()
public:
    UProductionSubsystem();

private:
    UFUNCTION(BlueprintCallable)
    void OnRegionRenamed(ARegion* inRegion, const FString& InNewName);
    
};

