#pragma once
#include "CoreMinimal.h"
#include "EItemSubcategory.h"
#include "RequirementCollection.generated.h"

USTRUCT(BlueprintType)
struct FRequirementCollection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EItemSubcategory> ItemSubcategories;
    
    MANORLORDS_API FRequirementCollection();
};
FORCEINLINE uint32 GetTypeHash(const FRequirementCollection) { return 0; }

