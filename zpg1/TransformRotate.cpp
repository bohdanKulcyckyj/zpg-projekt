#include "TransformRotate.h"

TransformRotate::TransformRotate(float angle, glm::vec3 axis)
{
	this->angle = angle;
	this->axis = axis;
	this->matrix = glm::rotate(glm::mat4(1.0), glm::radians(angle), axis);
}

glm::mat4 TransformRotate::computeTransform() {
	return this->matrix;
}