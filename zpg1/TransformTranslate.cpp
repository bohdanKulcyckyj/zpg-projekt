#include "TransformTranslate.h"

TransformTranslate::TransformTranslate(glm::vec3 translate)
{
	matrix = glm::translate(glm::mat4(1.0f), translate);
}