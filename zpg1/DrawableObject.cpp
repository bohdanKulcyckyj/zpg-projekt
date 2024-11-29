#include "DrawableObject.h"

DrawableObject::DrawableObject(ShaderProgram* sp, Model* m) {
	shaderProgram = sp;
	model = m;
}

void DrawableObject::draw() {
	this->shaderProgram->use();
	this->shaderProgram->updateUniform("modelMatrix", glm::value_ptr(transform->computeTransform()));
	this->model->draw();
	this->shaderProgram->unuse();
}

void DrawableObject::addTransform(Transform* t) {
	transform->addTransform(t);
	transform->computeTransform();
}