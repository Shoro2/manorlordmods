#include "ApprovalComponent.h"

UApprovalComponent::UApprovalComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ApprovalDataTable = NULL;
}

FName UApprovalComponent::GetCurrencyNameForApprovalEffect(const FName InEffect) {
    return NAME_None;
}

FApproval UApprovalComponent::GetApprovalData() const {
    return FApproval{};
}


