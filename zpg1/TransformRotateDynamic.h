#pragma once

#include "TransformRotate.h"

class TransformRotateDynamic : public TransformRotate
{
public:
	TransformRotateDynamic(float angle, glm::vec3 axis);
	glm::mat4 getMatrix();
};

