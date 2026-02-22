#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "MapDataRow.h"
#include "PaperMapFunctionLibrary.generated.h"

class UTexture2D;
class UTextureRenderTarget2D;
class UWorld;

UCLASS(Blueprintable)
class UPaperMapFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UPaperMapFunctionLibrary();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContext"))
    static void togglePaperMap(const UWorld* InWorldContext, const bool InVisible, const FMapDataRow& SourceMapData);
    
    UFUNCTION(BlueprintCallable)
    static UTexture2D* BuildMippedTextureFromRenderTarget(UTextureRenderTarget2D* InSourceImage);
    
};

