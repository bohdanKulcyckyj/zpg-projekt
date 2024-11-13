#pragma once

#include "Transform.h"

class TransformRotate : public Transform
{
public: 
	TransformRotate(float angle, glm::vec3 axis);
};

