#include "WindmillComponent.h"

UWindmillComponent::UWindmillComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

float UWindmillComponent::GetNaturalEfficiency() const {
    return 0.0f;
}


