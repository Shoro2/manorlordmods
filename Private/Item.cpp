#include "Item.h"

FItem::FItem() {
    this->Icon = NULL;
    this->bCombatType = false;
    this->EquipmentSlot = EEquipmentSlot::Body;
    this->equipmentSlotOverrideCivilian = EEquipmentSlot::Body;
    this->locomotionStance = ELocomotionStance::Default;
    this->att = 0.00f;
    this->rangedAtt = 0.00f;
    this->Def = 0.00f;
    this->Range = 0.00f;
    this->shootingRange = 0.00f;
    this->bLock = 0.00f;
    this->Speed = 0.00f;
    this->Mode = 0;
    this->Weight = 0.00f;
    this->charge = 0.00f;
    this->chargeStop = 0.00f;
    this->armorPierce = 0.00f;
    this->force1hAttacks = false;
    this->noStab = false;
    this->attackMethod = EAttackMethod::Mixed;
    this->craftingTool = 0;
    this->creationProg = 0.00f;
    this->ExpertiseOnCraft = 0.00f;
    this->tradeable = false;
    this->Value = 0.00f;
    this->isMajorTrade = false;
    this->spoilageRate = 0.00f;
    this->craftingAnim = 0;
    this->animID_pickup = 0;
    this->animID_putdown = 0;
    this->animID_carryIdle = 0;
    this->animID_carryWalk = 0;
    this->storageType = EStorageType::Generic;
    this->itemCategory = EItemCategory::None;
    this->Subcategory = EItemSubcategory::None;
    this->requirementLevel = 0;
    this->pickupSfx = NULL;
    this->putdownSfx = NULL;
    this->craftingSfx = NULL;
    this->LaborValue = 0;
}

