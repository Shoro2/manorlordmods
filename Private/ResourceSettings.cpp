#include "ResourceSettings.h"

UResourceSettings::UResourceSettings() {
    this->startleDistance = 4500.00f;
    this->resourceDepositRadius = 2000.00f;
    this->resourceRichDepositRadius = 2500.00f;
    this->MapDecalWorldSize = 2500.00f;
    this->MapDecalWorldSizeRich = 4000.00f;
    this->ElevationPercentage = 60;
    this->ElevationDeathPercentage = 7;
    this->MineableNodes.AddDefaulted(4);
    this->ResourceNodeData.AddDefaulted(10);
    this->ResourceClumpCollisionRadius = 200.00f;
}

FResourceNodeProperties UResourceSettings::GetPropertiesForType(ENodeType Type) const {
    return FResourceNodeProperties{};
}


