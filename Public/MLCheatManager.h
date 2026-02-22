#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=CheatManager -FallbackName=CheatManager
#include "MLCheatManager.generated.h"

UCLASS(Blueprintable)
class UMLCheatManager : public UCheatManager {
    GENERATED_BODY()
public:
    UMLCheatManager();

    UFUNCTION(BlueprintCallable, Exec)
    void UnmaintainAllBuildings();
    
    UFUNCTION(BlueprintCallable, Exec)
    void UnlockPerk(const FName& InPerkName, const int32 InSlotIndex);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SpawnBanditSquad();
    
    UFUNCTION(BlueprintCallable, Exec)
    void SettleRaiders();
    
    UFUNCTION(Exec)
    void SetSettlementLevel(const uint32 InSettlementLevel);
    
    UFUNCTION(BlueprintCallable, Exec)
    void SetFireToNumBuildings(const int32 NumBuildings);
    
    UFUNCTION(BlueprintCallable, Exec)
    void RemoveAllFamilies();
    
    UFUNCTION(BlueprintCallable, Exec)
    void Rebel();
    
    UFUNCTION(BlueprintCallable, Exec)
    void MaintainAllBuildings();
    
    UFUNCTION(BlueprintCallable, Exec)
    void LogAllProductionTrackerEntries();
    
    UFUNCTION(BlueprintCallable, Exec)
    void Injury(const uint8 InInjuryLevel);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GiveRandomAmountOfAllItems();
    
    UFUNCTION(BlueprintCallable, Exec)
    void GiveItemByName(const FString& InItemName, const int32 InCount);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GiveItemByID(const int32 InItemID, const int32 InCount);
    
    UFUNCTION(BlueprintCallable, Exec)
    void GiveFoodVariety();
    
    UFUNCTION(BlueprintCallable, Exec)
    void DumpVAInfo();
    
    UFUNCTION(BlueprintCallable, Exec)
    void CollapseAllBuildings();
    
    UFUNCTION(BlueprintCallable, Exec)
    void ChangeTreasury(const int32 InNewTreasury);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddItemToBuilding(const FString& InBuildingName, const FString& InItemName, const float InCount);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddExpertiseToSelection(int32 InExpertise);
    
};

