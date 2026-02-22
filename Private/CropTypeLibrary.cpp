#include "CropTypeLibrary.h"

UCropTypeLibrary::UCropTypeLibrary() {
}

bool UCropTypeLibrary::NeedsAlmostFullGrowthBeforeHarvest(ECropType Type) {
    return false;
}

bool UCropTypeLibrary::IsVegetableCropType(ECropType Type) {
    return false;
}

bool UCropTypeLibrary::IsFruitCropType(ECropType Type) {
    return false;
}

bool UCropTypeLibrary::IsFertilityBased(ECropType Type) {
    return false;
}

bool UCropTypeLibrary::IsBackyardCrop(ECropType Type) {
    return false;
}

int32 UCropTypeLibrary::GetItemIDFromCropType(ECropType Type) {
    return 0;
}


