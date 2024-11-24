#include "TransformRotateDynamic.h"

TransformRotateDynamic::TransformRotateDynamic(float angle, glm::vec3 axis) : TransformRotate(angle, axis) {

}
glm::mat4 TransformRotateDynamic::getMatrix() {
	printf("\n\n\nbruuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuh\n\n\n");
	this->matrix = glm::rotate(this->matrix, glm::radians(angle), axis);
	return this->matrix;
}