#pragma once

#include "ShaderProgram.h"
#include "TransformComposite.h"
#include "Model.h"
#include "Texture.h"
#include "Material.h"

class DrawableObject
{
private:
	ShaderProgram* shaderProgram;
	TransformComposite* transform = new TransformComposite();
	Model* model;
	Material* material;
	Texture* texture;

	glm::mat4 M = glm::mat4(1.0f);
	float alpha = 0;
public:
	DrawableObject(ShaderProgram* sp, Model* m);
	DrawableObject(ShaderProgram* sp, Model* m, Material* mat);
	DrawableObject(ShaderProgram* sp, Model* m, Texture* t);
	DrawableObject(ShaderProgram* sp, Model* m, Material* mat, Texture* t);
	void draw();
	void addTransform(Transform* t);
};

