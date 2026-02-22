#include "SavedResourceNode.h"

FSavedResourceNode::FSavedResourceNode() {
    this->nodeType = ENodeType::None;
    this->bRichNode = false;
    this->maxResourceCount = 0;
    this->resourceCount = 0;
    this->squadID = 0;
}

