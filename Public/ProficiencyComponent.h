#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "OnProficiencyChangedDelegate.h"
#include "ProductivityBracket.h"
#include "ProductivityFactor.h"
#include "ProficiencyComponent.generated.h"

class UExpertiseComponent;
class UMaintenanceComponent;
class UPerkSettings;
class UProficiencySettings;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UProficiencyComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnProficiencyChanged OnProficiencyChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UMaintenanceComponent* MaintenanceComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UExpertiseComponent* ExpertiseComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPerkSettings* PerkSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UProficiencySettings* ProficiencySettings;
    
public:
    UProficiencyComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateProficiency();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetProficiencyFromMaintenanceState(const UMaintenanceComponent* InComponent) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetProductivityMultiplier() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FProductivityFactor> GetProductivityFactors() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FProductivityBracket GetCurrentBracket() const;
    
};

