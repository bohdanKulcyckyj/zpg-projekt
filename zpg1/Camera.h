#pragma once

#include <GL/glew.h>
//Include GLFW
#include <GLFW/glfw3.h> 

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include "Subject.h"

#define PROJECTIONMATRIX 0
#define VIEWMATRIX 1

class Camera : public Subject
{
private:
	GLFWwindow* window;

	glm::vec3 position = glm::vec3(5.0f, 2.0f, 0.0f); // glm::vec3(5.0f, 0.0f, 0.0f);
	glm::vec3 up = glm::vec3(0.f, 1.f, 0.f);
	glm::vec3 target = glm::vec3(-5.0f, 0.0f, 0.0f);

	float speed = 0.05f;
	float ratio = 0;
	float fov;
	float near;
	float far;

	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

	int prevWidth = 0;
	int prevHeight = 0;
	int currWidth = 0;
	int currHeight = 0;

	glm::vec3 prevPosition = glm::vec3(0.0f);
	glm::vec3 prevTarget = glm::vec3(0.0f);
public:
	Camera(GLFWwindow* w);
	// getters
	glm::vec3 getPosition();
	glm::vec3 getDirection();
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();
	glm::mat4 getCamera();

	bool hasViewMatrixChanged();
	bool hasProjectionMatrixChanged();
	void checkForChanges();

	void computeViewMatrix();
	void computeProjectionMatrix();
	void controls();

	void notifyAll(int message) override;
};
