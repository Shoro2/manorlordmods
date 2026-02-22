#include "Resource.h"

AResource::AResource(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Region = NULL;
    this->belongsTo = NULL;
    this->DisplayName = TEXT("Resource");
    this->amt = 0;
    this->Type = 0;
    this->capacity = 0;
    this->bSeasonal = false;
}

void AResource::startFalling_Implementation() {
}

void AResource::setFalling(bool newSetting) {
}

void AResource::removeResource_Implementation() {
}

ARTSMultiEngineCPP* AResource::getMaster() {
    return NULL;
}


