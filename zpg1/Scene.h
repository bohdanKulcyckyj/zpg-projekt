#pragma once

#include "DrawableObject.h"
#include "Controller.h"
#include "Camera.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "TreeModel.h"
#include "TransformRotate.h"
#include "TransformScale.h"
#include "TransformTranslate.h"
#include "Vertex.h"

class Scene
{
private:
	vector<DrawableObject*> objects;
	GLFWwindow* window;
	Camera* camera;
public:
	Scene(GLFWwindow* w);
	void registerCallbacks();
	void initModels();
	void render();
};

