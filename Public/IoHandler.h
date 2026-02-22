#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "EIoFileCategory.h"
#include "IoHandler.generated.h"

class USaveGame;

UCLASS(Blueprintable)
class MANORLORDS_API UIoHandler : public UObject {
    GENERATED_BODY()
public:
    UIoHandler();

    UFUNCTION(BlueprintCallable)
    static bool SaveGameToSlot(USaveGame* SaveGameObject, const FString& SlotName, EIoFileCategory ioCategory);
    
    UFUNCTION(BlueprintCallable)
    static bool SaveDataToSlot(const TArray<uint8>& InSaveData, const FString& SlotName, EIoFileCategory ioCategory);
    
    UFUNCTION(BlueprintCallable)
    static void PurgeSaveFileWriteCache();
    
    UFUNCTION(BlueprintCallable)
    static USaveGame* LoadGameFromSlot(const FString& SlotName);
    
    UFUNCTION(BlueprintCallable)
    static bool LoadDataFromSlot(TArray<uint8>& OutSaveData, const FString& SlotName);
    
    UFUNCTION(BlueprintCallable)
    static bool IsSaving();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetMaxMapFileSize();
    
    UFUNCTION(BlueprintCallable)
    static bool DoesSaveGameExist(const FString& SlotName);
    
    UFUNCTION(BlueprintCallable)
    static bool DeleteGameInSlot(const FString& SlotName);
    
};

