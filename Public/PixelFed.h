#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "EPixelFedBackendId.h"
#include "PixelFedBackend.h"
#include "PixelFedConfiguration.h"
#include "PixelFedFullChoiceState.h"
#include "PixelFedSetupFinishedDelegate.h"
#include "PixelFedState.h"
#include "PixelFed.generated.h"

class UMLGameInstance;

UCLASS(Blueprintable)
class MANORLORDS_API UPixelFed : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPixelFedState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMLGameInstance* backbone;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPixelFedSetupFinished uponSetupFinished;
    
    UPixelFed();

    UFUNCTION(BlueprintCallable)
    void ReportInFullscreenmenu(bool inMenu);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EPixelFedBackendId> ListAllPotentialBackends() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasSetupFinished() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetShowFps() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    void FindFps(const UObject* WorldContext, float& fps, float& fpsSmoothed);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool FindBackendIdByName(const FString& backendName, EPixelFedBackendId& backendId) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool FindBackendByName(const FString& backendName, FPixelFedBackend& backend) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool FindBackendActiveOrPreferredQuality(EPixelFedBackendId backendId, FName& Quality) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool FindBackendActiveOrPreferredFramegen(EPixelFedBackendId backendId, FName& framegen) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool FindActiveBackendName(FString& backendName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool FindActiveBackendId(EPixelFedBackendId& backendId) const;
    
    UFUNCTION(BlueprintCallable)
    void DoSetScreenPercentageNonOverriding(float ScreenPercentage);
    
    UFUNCTION(BlueprintCallable)
    void DoReconfigureBackend(FPixelFedConfiguration request, bool isPlayerPrefernce);
    
    UFUNCTION(BlueprintCallable)
    FPixelFedFullChoiceState ComputeFullState();
    
};

