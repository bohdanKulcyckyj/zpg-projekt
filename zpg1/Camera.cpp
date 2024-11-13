#include "Camera.h"

Camera::Camera(GLFWwindow* w) {
	this->window = w;
}

glm::mat4 Camera::getCamera(void) {
	return glm::lookAt(position, position + target, up);
}

void Camera::controls() {
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		position += speed * target;
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		position -= speed * target;
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		position -= speed * glm::normalize(glm::cross(target, up));
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		position += speed * glm::normalize(glm::cross(target, up));
	}
}

glm::vec3 Camera::getPosition()
{
	return this->position;
}

glm::vec3 Camera::getDirection()
{
	return this->target;
}

glm::mat4 Camera::getViewMatrix()
{
	return this->viewMatrix;
}

glm::mat4 Camera::getProjectionMatrix()
{
	return this->projectionMatrix;
}

void Camera::checkForChanges()
{
	if (hasProjectionMatrixChanged())
	{
		printf("projectionMatrixChanged\n");
		notifyAll(PROJECTIONMATRIX);
	}
	if (hasViewMatrixChanged())
	{
		printf("viewMatrixChanged\n");
		notifyAll(VIEWMATRIX);
	}
}
bool Camera::hasViewMatrixChanged()
{
	if (prevPosition != position || prevTarget != target)
	{
		prevPosition = position;
		prevTarget = target;
		computeViewMatrix();

		return true;
	}
	return false;
}

bool Camera::hasProjectionMatrixChanged()
{
	glfwGetWindowSize(window, &currWidth, &currHeight);

	if (currWidth != prevWidth || currHeight != prevHeight)
	{
		ratio = float(currWidth) / float(currHeight);
		prevWidth = currWidth;
		prevHeight = currHeight;
		computeProjectionMatrix();

		return true;
	}

	return false;
}

void Camera::computeViewMatrix() {
	this->viewMatrix = glm::lookAt(position, position + target, up);
}

void Camera::computeProjectionMatrix() {
	this->projectionMatrix = glm::perspective(glm::radians(fov), ratio, near, far);
}

void Camera::notifyAll(int message) {
	for (auto o : observers) {
		o->update(message);
	}
}


