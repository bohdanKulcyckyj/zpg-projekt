#include "TransformRotateDynamic.h"

TransformRotateDynamic::TransformRotateDynamic(float angle, glm::vec3 axis, float speed) : TransformRotate(angle, axis) {
	this->angle = angle;
	this->speed = speed;
}
glm::mat4 TransformRotateDynamic::computeTransform() {
	this->matrix = glm::rotate(this->getMatrix(), glm::radians(speed), axis);
	return this->matrix;
}