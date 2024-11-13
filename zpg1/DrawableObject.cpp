#include "DrawableObject.h"

DrawableObject::DrawableObject(ShaderProgram* sp, Model* m) {
	shaderProgram = sp;
	model = m;
}

void DrawableObject::draw() {
	this->shaderProgram->use();

	alpha += 0.0001;
	//this->M = glm::rotate(glm::mat4(1.0f), alpha, glm::vec3(0.0f, 0.0f, 1.0f));
	this->shaderProgram->updateUniform("modelMatrix", glm::value_ptr(transform->getMatrix())/*glm::value_ptr(M)*/);
	/*
	M = glm::lookAt(glm::vec3(5.0f + alpha * 100, 0.0f, 0.0f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.f, 0.f));
	this->shaderProgram->updateUniform("viewMatrix", glm::value_ptr(M));
	*/
	M = glm::perspective(45.0f, 800.f / 600.f, 0.1f, 100.0f);
	this->shaderProgram->updateUniform("projectionMatrix", glm::value_ptr(M));

	this->model->draw();
}

void DrawableObject::addTransform(Transform* t) {
	transform->addTransform(t);
	transform->computeTransform();
}