#include "DrawableObject.h"

DrawableObject::DrawableObject(ShaderProgram* sp, Model* m) {
	shaderProgram = sp;
	model = m;
}

void DrawableObject::draw() {
	this->shaderProgram->use();

	alpha += 0.0001;
	//this->M = glm::rotate(glm::mat4(1.0f), alpha, glm::vec3(0.0f, 0.0f, 1.0f));
	this->shaderProgram->updateUniform("modelMatrix", glm::value_ptr(transform->computeTransform())/*glm::value_ptr(M)*/);
	
	M = glm::perspective(45.0f, 800.f / 600.f, 0.1f, 100.0f); // tohle by se melo updatovat po onresize
	this->shaderProgram->updateUniform("projectionMatrix", glm::value_ptr(M));
	
	this->model->draw();

	this->shaderProgram->unuse();
}

void DrawableObject::addTransform(Transform* t) {
	transform->addTransform(t);
	transform->computeTransform();
}