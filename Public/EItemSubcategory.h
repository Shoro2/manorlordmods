#pragma once
#include "CoreMinimal.h"
#include "EItemSubcategory.generated.h"

UENUM(BlueprintType)
enum class EItemSubcategory : uint8 {
    None,
    Woodworks,
    Stoneworks,
    Maintenance,
    Roofing,
    Vegetables,
    Meats,
    Grains,
    ForagedGoods,
    Fruits,
    AnimalProduce,
    Preserves,
    Fishes,
    Ingredients,
    Textiles,
    Minerals,
    Metalworks,
    Fuels,
    Crops,
    Clothing,
    Shoes,
    Beverage,
    MeleeWeapons,
    RangedWeapons,
    Shields,
    Armor,
    WaterAccess,
    ChurchAccess,
    MAX,
};

