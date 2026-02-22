#pragma once
#include "CoreMinimal.h"
#include "ENoticeSquadSetting.generated.h"

UENUM(BlueprintType)
enum class ENoticeSquadSetting : uint8 {
    Nothing,
    SlowGame,
    Pause,
};

