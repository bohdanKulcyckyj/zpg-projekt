#include "TransformScaleDynamic.h"

TransformScaleDynamic::TransformScaleDynamic(glm::vec3 scale, float speed) : TransformScale(scale)
{
	this->scale = scale;
	this->speed = speed;
}

glm::mat4 TransformScaleDynamic::computeTransform() {
	this->scale += this->speed;
	this->matrix = glm::scale(glm::mat4(1.0f), this->scale);
	return this->matrix;
}