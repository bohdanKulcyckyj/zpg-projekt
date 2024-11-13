#pragma once

#include "ShaderProgram.h"
#include "TransformComposite.h"
#include "Model.h"

class DrawableObject
{
private:
	ShaderProgram* shaderProgram;
	TransformComposite* transform = new TransformComposite();
	Model* model;

	glm::mat4 M = glm::mat4(1.0f);
	float alpha = 0;
public:
	DrawableObject(ShaderProgram* sp, Model* m);
	void draw();
	void addTransform(Transform* t);
};

