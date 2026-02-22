#include "Proj.h"

FProj::FProj() {
    this->Type = 0;
    this->Height = 0.00f;
    this->InstanceId = 0;
    this->progress = 0.00f;
    this->inGround = 0.00f;
    this->hasHit = false;
    this->shooter = NULL;
    this->incr = 0.00f;
}

