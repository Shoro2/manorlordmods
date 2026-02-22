#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=UserWidget -FallbackName=UserWidget
#include "ApprovalWidget.generated.h"

class USizeBox;

UCLASS(Blueprintable, EditInlineNew)
class MANORLORDS_API UApprovalWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USizeBox* ApprovalPercentContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USizeBox* arrow;
    
public:
    UApprovalWidget();

    UFUNCTION(BlueprintCallable)
    void UpdateArrowPosition(const int32 InApprovalRating);
    
};

