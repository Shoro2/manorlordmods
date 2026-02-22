#include "GateComponent.h"

UGateComponent::UGateComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bGatesOpened = true;
}

void UGateComponent::ToggleGatesOpen() {
}

bool UGateComponent::AreGatesAnimating() {
    return false;
}


