#include "TransformTranslateDynamic.h"

TransformTranslateDynamic::TransformTranslateDynamic(glm::vec3 translate, float speed) : TransformTranslate(translate)
{
	this->translate = translate;
	this->speed = speed;
}

glm::mat4 TransformTranslateDynamic::computeTransform() {
	this->translate += speed;
	this->matrix = glm::translate(glm::mat4(1.0f), this->translate);
	return this->matrix;
}