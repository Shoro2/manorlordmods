#include "Paragraph.h"

FParagraph::FParagraph() {
    this->Category = 0;
    this->numTextVariations = 0;
    this->cost = 0;
    this->relations = 0;
    this->useOnlyOnce = false;
    this->minRelationship = 0;
    this->maxRelationship = 0;
    this->paraPick = EParaPick::None;
    this->Score = 0.00f;
}

