#include "RTSSettings.h"

FRTSSettings::FRTSSettings() {
    this->colorCoding = ESettingColorCoding::RandomColors;
    this->showTutorials = false;
    this->showAllProblems = false;
    this->multipleControlGroupsAllowed = false;
    this->exposure_sunny = 0.00f;
    this->exposure_cloudy = 0.00f;
    this->camera_fov = 0.00f;
    this->camera_shake = false;
    this->camera_speed = 0.00f;
    this->camera_freeTilt = 0;
    this->camera_cumulativeRotation = false;
    this->camera_scaleRotationWhenZoomed = false;
    this->camera_rotationSpeed = 0.00f;
    this->camera_rotationSmoothness = 0.00f;
    this->camera_tiltSensitivity = 0.00f;
    this->camera_zoomSpeed = 0.00f;
    this->camera_zoomToCursor = 0.00f;
    this->graphics_fullscreenMode = 0;
    this->volumetricClouds = false;
    this->CloudShadows = false;
    this->graphics_vsync = false;
    this->graphics_cascades = 0;
    this->graphics_contactShadows = false;
    this->graphics_SSGI = false;
    this->graphics_SSGI_halfres = false;
    this->scalability_aa = 0;
    this->scalability_shadows = 0;
    this->scalability_material = 0;
    this->scalability_viewdistanceMultiplier = 0.00f;
    this->scalability_postprocess = 0;
    this->scalability_textures = 0;
    this->scalability_fx = 0;
    this->scalability_foliageDensity = 0;
    this->scalability_resolutionScale = 0.00f;
    this->hud_showResourceIcons = false;
    this->userInterfaceScale = 0.00f;
    this->mouseLock = 0;
    this->useDayNightCycle = false;
    this->autosavePeriod = 0.00f;
    this->noticeEnemyBehaviour = 0;
    this->useTutorials = false;
    this->alwaysShowResourceIcons = false;
    this->useVolumetricClouds = false;
    this->edgeScrolling = false;
    this->GrassDensity = 0.00f;
    this->grassRenderingDistance = 0.00f;
}

