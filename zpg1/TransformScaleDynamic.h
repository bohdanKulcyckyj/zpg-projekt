#pragma once

#include "TransformScale.h"

class TransformScaleDynamic : public TransformScale
{
private:
	glm::vec3 scale;
	float speed = 0;
public:
	TransformScaleDynamic(glm::vec3 scale, float speed);
	glm::mat4 computeTransform() override;
};

