#include "IoHandler.h"

UIoHandler::UIoHandler() {
}

bool UIoHandler::SaveGameToSlot(USaveGame* SaveGameObject, const FString& SlotName, EIoFileCategory ioCategory) {
    return false;
}

bool UIoHandler::SaveDataToSlot(const TArray<uint8>& InSaveData, const FString& SlotName, EIoFileCategory ioCategory) {
    return false;
}

void UIoHandler::PurgeSaveFileWriteCache() {
}

USaveGame* UIoHandler::LoadGameFromSlot(const FString& SlotName) {
    return NULL;
}

bool UIoHandler::LoadDataFromSlot(TArray<uint8>& OutSaveData, const FString& SlotName) {
    return false;
}

bool UIoHandler::IsSaving() {
    return false;
}

int32 UIoHandler::GetMaxMapFileSize() {
    return 0;
}

bool UIoHandler::DoesSaveGameExist(const FString& SlotName) {
    return false;
}

bool UIoHandler::DeleteGameInSlot(const FString& SlotName) {
    return false;
}


