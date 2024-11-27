#pragma once

#include "Transform.h"

class TransformTranslate : public Transform
{
public:
	TransformTranslate(glm::vec3 translate);
	glm::mat4 computeTransform() override;
};

