#pragma once
#include "CoreMinimal.h"
#include "ESkillType.generated.h"

UENUM(BlueprintType)
enum class ESkillType : uint8 {
    Disband,
    Settle,
    ShieldWall,
    FireAtWill,
    SpreadOut,
    Halt = 8,
    SprintToggle,
    Rally = 11,
    RemoveSquad,
    Encamp = 14,
    AttackGates,
    BuildSiegeCamp,
};

