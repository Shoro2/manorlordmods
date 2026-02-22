#pragma once
#include "CoreMinimal.h"
#include "ENodeType.h"
#include "ResourceNodeProperties.h"
#include "ResourceNodeData.generated.h"

USTRUCT(BlueprintType)
struct FResourceNodeData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ENodeType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FResourceNodeProperties Properties;
    
    MANORLORDS_API FResourceNodeData();
};

