#include "SMSiegeUnit.h"

ASMSiegeUnit::ASMSiegeUnit(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->animRandomVariation = 33;
    this->VAMPControllers.AddDefaulted(8);
}


