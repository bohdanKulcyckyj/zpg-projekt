#pragma once

#include "TransformTranslate.h"

class TransformTranslateDynamic : public TransformTranslate
{
private:
	glm::vec3 translate;
	float speed;
public:
	TransformTranslateDynamic(glm::vec3 translate, float speed);
	glm::mat4 computeTransform() override;
};

