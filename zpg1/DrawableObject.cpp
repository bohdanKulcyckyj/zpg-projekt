#include "DrawableObject.h"

DrawableObject::DrawableObject(ShaderProgram* sp, Model* m) {
	shaderProgram = sp;
	model = m;
}

DrawableObject::DrawableObject(ShaderProgram* sp, Model* m, Material* mat) {
	shaderProgram = sp;
	model = m;
	material = mat;
}

DrawableObject::DrawableObject(ShaderProgram* sp, Model* m, Texture* t) {
	shaderProgram = sp;
	model = m;
	texture = t;
}

DrawableObject::DrawableObject(ShaderProgram* sp, Model* m, Material* mat, Texture* t) {
	shaderProgram = sp;
	model = m;
	material = mat;
	texture = t;
}

void DrawableObject::draw() {
	this->shaderProgram->use();
	if (texture != nullptr) {
		this->shaderProgram->updateUniform("textureUnitID", this->texture->getPosition());
	}
	this->shaderProgram->updateUniform("modelMatrix", glm::value_ptr(transform->computeTransform()));
	if (material != nullptr) {
		this->shaderProgram->updateUniform("amb", this->material->getAmbient());
		this->shaderProgram->updateUniform("diff", this->material->getDiffuse());
		this->shaderProgram->updateUniform("spec", this->material->getSpecularStrength());
		this->shaderProgram->updateUniform("modelColor", this->material->getObjColor());
		this->shaderProgram->updateUniform("powExponent", this->material->getSpecIntensity());
	}
	// this->shaderProgram->update();
	this->model->draw();
	this->shaderProgram->unuse();
}

void DrawableObject::addTransform(Transform* t) {
	transform->addTransform(t);
	transform->computeTransform();
}