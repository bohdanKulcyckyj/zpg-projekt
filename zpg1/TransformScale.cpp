#include "TransformScale.h"

TransformScale::TransformScale(glm::vec3 scale)
{
	this->matrix = glm::scale(glm::mat4(1.0f), scale);
}

glm::mat4 TransformScale::computeTransform() {
	return this->matrix;
}