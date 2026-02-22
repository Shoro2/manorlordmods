#include "ProficiencyComponent.h"

UProficiencyComponent::UProficiencyComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MaintenanceComponent = NULL;
    this->ExpertiseComponent = NULL;
}

void UProficiencyComponent::UpdateProficiency() {
}

int32 UProficiencyComponent::GetProficiencyFromMaintenanceState(const UMaintenanceComponent* InComponent) const {
    return 0;
}

float UProficiencyComponent::GetProductivityMultiplier() const {
    return 0.0f;
}

TArray<FProductivityFactor> UProficiencyComponent::GetProductivityFactors() const {
    return TArray<FProductivityFactor>();
}

FProductivityBracket UProficiencyComponent::GetCurrentBracket() const {
    return FProductivityBracket{};
}


