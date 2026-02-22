#include "ApprovalWidget.h"

UApprovalWidget::UApprovalWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->ApprovalPercentContainer = NULL;
    this->arrow = NULL;
}

void UApprovalWidget::UpdateArrowPosition(const int32 InApprovalRating) {
}


