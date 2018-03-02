#pragma once
#include "head.h"
class Model {
public:	Model();
public: ~Model();


protected: shader Shader;
protected: glm::mat4 model;
protected: const uint_32 positionAttributeIndex, colorAttributeIndex;
};

