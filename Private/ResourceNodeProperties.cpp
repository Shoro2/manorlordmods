#include "ResourceNodeProperties.h"

FResourceNodeProperties::FResourceNodeProperties() {
    this->bIsLimitedResource = false;
    this->bUndergroundDepositsWhenRich = false;
    this->ResourceTypeID = EItemType::None;
    this->resourceCount = 0;
    this->MinResourceAmount = 0;
    this->MaxResourceAmount = 0;
    this->MinRichResourceAmount = 0;
    this->MaxRichResourceAmount = 0;
    this->bApplyRandomRotation = false;
    this->ResourceTemplate = NULL;
    this->Icon = NULL;
    this->PaperMapMaterial = NULL;
    this->RichPaperMapMaterial = NULL;
    this->ZoneMaterial = NULL;
    this->RichZoneMaterial = NULL;
    this->BreedingThreshold = 0;
}

