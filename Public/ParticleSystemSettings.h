#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=DeveloperSettings -ObjectName=DeveloperSettings -FallbackName=DeveloperSettings
#include "ParticleSystemSettings.generated.h"

class UNiagaraSystem;
class UParticleSystem;

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class UParticleSystemSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNiagaraSystem> PS_UnitMoveConfirmation;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, TSoftObjectPtr<UParticleSystem>> ParticleSystems;
    
    UParticleSystemSettings();

};

