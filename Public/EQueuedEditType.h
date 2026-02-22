#pragma once
#include "CoreMinimal.h"
#include "EQueuedEditType.generated.h"

UENUM(BlueprintType)
enum class EQueuedEditType : uint8 {
    AddPP,
    EditPP,
    RemovePP,
    AddObstacle,
    EditObstacle,
    RemoveObstacle,
    AddBorderObstacle,
    EditBorderObstacle,
    RemoveBorderObstacle,
    AddSnapPoint,
    EditSnapPoint,
    RemoveSnapPoint,
    ShiftSquadIDsOver,
};

