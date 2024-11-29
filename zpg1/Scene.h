#pragma once

#include "DrawableObject.h"
#include "Controller.h"
#include "Camera.h"
#include "Triangle.h"
#include "Rectangle.h"

// Models
#include "TreeModel.h"
#include "SphereModel.h"

#include "TransformRotate.h"
#include "TransformRotateDynamic.h"
#include "TransformScale.h"
#include "TransformScaleDynamic.h"
#include "TransformTranslate.h"
#include "TransformTranslateDynamic.h"
#include "Vertex.h"
#include "Light.h"
#include "LightManager.h";

class Scene
{
protected:
	vector<DrawableObject*> objects;
	GLFWwindow* window;
	Camera* camera;
public:
	Scene(GLFWwindow* w);
	void registerCallbacks();
	virtual void init() = 0;
	void render();
};

