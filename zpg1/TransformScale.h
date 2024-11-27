#pragma once

#include "Transform.h"

class TransformScale : public Transform
{
public:
	TransformScale(glm::vec3 scale);
	glm::mat4 computeTransform() override;
};

