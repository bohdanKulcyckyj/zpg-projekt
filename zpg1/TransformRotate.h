#pragma once

#include "Transform.h"

class TransformRotate : public Transform
{
protected:
	float angle;
	glm::vec3 axis;
public: 
	TransformRotate(float angle, glm::vec3 axis);
};

