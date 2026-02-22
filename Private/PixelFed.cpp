#include "PixelFed.h"

UPixelFed::UPixelFed() {
    this->backbone = NULL;
}

void UPixelFed::ReportInFullscreenmenu(bool inMenu) {
}

TArray<EPixelFedBackendId> UPixelFed::ListAllPotentialBackends() const {
    return TArray<EPixelFedBackendId>();
}

bool UPixelFed::HasSetupFinished() const {
    return false;
}

bool UPixelFed::GetShowFps() const {
    return false;
}

void UPixelFed::FindFps(const UObject* WorldContext, float& fps, float& fpsSmoothed) {
}

bool UPixelFed::FindBackendIdByName(const FString& backendName, EPixelFedBackendId& backendId) const {
    return false;
}

bool UPixelFed::FindBackendByName(const FString& backendName, FPixelFedBackend& backend) const {
    return false;
}

bool UPixelFed::FindBackendActiveOrPreferredQuality(EPixelFedBackendId backendId, FName& Quality) const {
    return false;
}

bool UPixelFed::FindBackendActiveOrPreferredFramegen(EPixelFedBackendId backendId, FName& framegen) const {
    return false;
}

bool UPixelFed::FindActiveBackendName(FString& backendName) const {
    return false;
}

bool UPixelFed::FindActiveBackendId(EPixelFedBackendId& backendId) const {
    return false;
}

void UPixelFed::DoSetScreenPercentageNonOverriding(float ScreenPercentage) {
}

void UPixelFed::DoReconfigureBackend(FPixelFedConfiguration request, bool isPlayerPrefernce) {
}

FPixelFedFullChoiceState UPixelFed::ComputeFullState() {
    return FPixelFedFullChoiceState{};
}


