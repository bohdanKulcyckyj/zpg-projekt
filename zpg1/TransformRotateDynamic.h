#pragma once

#include "TransformRotate.h"

class TransformRotateDynamic : public TransformRotate
{
private: 
	float angle = 0;
	float speed = 0;
public:
	TransformRotateDynamic(float angle, glm::vec3 axis, float speed);
	glm::mat4 computeTransform() override;
};

