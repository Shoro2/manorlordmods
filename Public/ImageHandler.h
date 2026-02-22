#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "ImageHandler.generated.h"

class UTexture2D;
class UTextureRenderTarget2D;

UCLASS(Blueprintable)
class MANORLORDS_API UImageHandler : public UObject {
    GENERATED_BODY()
public:
    UImageHandler();

    UFUNCTION(BlueprintCallable)
    static bool WriteImageToDisk(UTextureRenderTarget2D* TextureRenderTarget, const FString& SlotName);
    
private:
    UFUNCTION(BlueprintCallable)
    static bool UseWrapper(const FString& SlotName);
    
public:
    UFUNCTION(BlueprintCallable)
    static UTexture2D* ReadImageFromDisk(const FString& SlotName);
    
private:
    UFUNCTION(BlueprintCallable)
    static void log(const FString& Msg);
    
public:
    UFUNCTION(BlueprintCallable)
    static bool IsImageOnDisk(const FString& SlotName);
    
    UFUNCTION(BlueprintCallable)
    static bool DeleteImageOnDisk(const FString& SlotName);
    
private:
    UFUNCTION(BlueprintCallable)
    static FString ComputeImageSlot(const FString& SlotName);
    
    UFUNCTION(BlueprintCallable)
    static FString ComputeImagePath(const FString& SlotName);
    
};

