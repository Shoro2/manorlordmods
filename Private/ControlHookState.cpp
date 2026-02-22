#include "ControlHookState.h"

FControlHookState::FControlHookState() {
    this->hasPlatformInited = false;
    this->activeMenu = NULL;
    this->isActiveMenuPureUi = false;
    this->isActivePriorityUi = false;
    this->inExploreMode = false;
    this->lastUsedInputMode = EControlInputMode::MouseKeyboard;
    this->P = NULL;
    this->pCon = NULL;
    this->ignoreInputModeChanges = false;
    this->forceGamepad = false;
    this->buildingRotateDir = 0.00f;
    this->forceCtrlPressed = false;
    this->analogRightIsOrbit = false;
    this->didAcceptGotoUi = false;
}

