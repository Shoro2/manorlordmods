#include "BuildingTemplate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BoxComponent -FallbackName=BoxComponent

ABuildingTemplate::ABuildingTemplate(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Shape"));
    this->Shape = (UBoxComponent*)RootComponent;
    this->masterPtr = NULL;
    this->bType = 0;
    this->ownershipByRegion = true;
    this->Region = NULL;
    this->snapToNearestRoad = false;
}


