#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "GraphicsPreset.h"
#include "GraphicsSettingsPresets.generated.h"

UCLASS(Blueprintable)
class UGraphicsSettingsPresets : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<uint8, FGraphicsPreset> Presets;
    
    UGraphicsSettingsPresets();

};

