#pragma once
#include "CoreMinimal.h"
#include "MaintenanceTypes.generated.h"

USTRUCT(BlueprintType)
struct FMaintenanceTypes {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> GoodTypes;
    
    MANORLORDS_API FMaintenanceTypes();
};
FORCEINLINE uint32 GetTypeHash(const FMaintenanceTypes) { return 0; }

