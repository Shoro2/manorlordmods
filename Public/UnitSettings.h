#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=DeveloperSettings -ObjectName=DeveloperSettings -FallbackName=DeveloperSettings
#include "ETaskType.h"
#include "UnitSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UUnitSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ETaskType> AllowedTasks;
    
    UUnitSettings();

};

