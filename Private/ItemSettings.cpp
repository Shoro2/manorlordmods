#include "ItemSettings.h"

UItemSettings::UItemSettings() {
}

TSoftObjectPtr<UTexture2D> UItemSettings::GetIconForItemSubcategory(const EItemSubcategory InSubcategory) {
    return NULL;
}

TSoftObjectPtr<UTexture2D> UItemSettings::GetIconForItemCategory(const EItemCategory InCategory) {
    return NULL;
}


