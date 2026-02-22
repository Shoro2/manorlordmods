#include "ControlHook.h"

UControlHook::UControlHook(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool UControlHook::ShowControllerCursors() {
    return false;
}

void UControlHook::SetInPriorityWindow(bool inPriorityWindow) {
}

void UControlHook::SetFlowInTutorial(bool inTutorial) {
}

void UControlHook::SetFlowInFullscreen(bool inFullscreen) {
}

void UControlHook::SetFlowInExplore(bool inExplore) {
}

void UControlHook::SetFlow(FControlHookFlow newFlow) {
}

void UControlHook::SendMouseToCenter() {
}

void UControlHook::SendInput(ENaviUiIntent intent) {
}

void UControlHook::SendAcceptToTool() {
}

UTexture2D* UControlHook::GetInputIcon(EInputIconButton Button) {
    return NULL;
}

FControlHookFlow UControlHook::GetFlow() {
    return FControlHookFlow{};
}

void UControlHook::BindActiveUi(UNaviUi* rootUi, bool isPureUi) {
}


