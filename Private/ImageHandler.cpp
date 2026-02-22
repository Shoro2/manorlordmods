#include "ImageHandler.h"

UImageHandler::UImageHandler() {
}

bool UImageHandler::WriteImageToDisk(UTextureRenderTarget2D* TextureRenderTarget, const FString& SlotName) {
    return false;
}

bool UImageHandler::UseWrapper(const FString& SlotName) {
    return false;
}

UTexture2D* UImageHandler::ReadImageFromDisk(const FString& SlotName) {
    return NULL;
}

void UImageHandler::log(const FString& Msg) {
}

bool UImageHandler::IsImageOnDisk(const FString& SlotName) {
    return false;
}

bool UImageHandler::DeleteImageOnDisk(const FString& SlotName) {
    return false;
}

FString UImageHandler::ComputeImageSlot(const FString& SlotName) {
    return TEXT("");
}

FString UImageHandler::ComputeImagePath(const FString& SlotName) {
    return TEXT("");
}


