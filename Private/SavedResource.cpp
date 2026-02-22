#include "SavedResource.h"

FSavedResource::FSavedResource() {
    this->capacity = 0;
    this->grownThisYear = 0;
    this->amt = 0;
    this->Type = 0;
    this->falling = false;
    this->bSeasonal = false;
    this->bRichDeposit = false;
}

