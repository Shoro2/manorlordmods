#include "BuildingTypeLibrary.h"

UBuildingTypeLibrary::UBuildingTypeLibrary() {
}

bool UBuildingTypeLibrary::HasYearlyYield(ASMBuildingMaster* InBuildingMaster) {
    return false;
}

bool UBuildingTypeLibrary::CanCauseDeforestation(int32 InBuildingType) {
    return false;
}


