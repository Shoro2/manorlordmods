#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=WidgetComponent -FallbackName=WidgetComponent
#include "TxtLoaderWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MANORLORDS_API UTxtLoaderWidget : public UWidgetComponent {
    GENERATED_BODY()
public:
    UTxtLoaderWidget(const FObjectInitializer& ObjectInitializer);

};

