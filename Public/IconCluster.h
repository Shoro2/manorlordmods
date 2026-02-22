#pragma once
#include "CoreMinimal.h"
#include "SquadIcon.h"
#include "IconCluster.generated.h"

USTRUCT(BlueprintType)
struct FIconCluster {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSquadIcon> Icons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> iconIDs;
    
    MANORLORDS_API FIconCluster();
};

