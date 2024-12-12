#include "Camera.h"

Camera::Camera(GLFWwindow* w) {
	this->window = w;
	computeProjectionMatrix();
	computeViewMatrix();
}

glm::mat4 Camera::getCamera(void) {
	return glm::lookAt(eye, eye + target, up);
}

void Camera::controls() {
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		eye += speed * target;
		updateFlashlight();
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		eye -= speed * target;
		updateFlashlight();
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		eye -= speed * glm::normalize(glm::cross(target, up));
		updateFlashlight();
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		eye += speed * glm::normalize(glm::cross(target, up));
		updateFlashlight();
	}

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
	{
		if (isFirstClick)
		{
			startPos->x = currWidth / 2;
			startPos->y = currHeight / 2;
			glfwSetCursorPos(window, startPos->x, startPos->y);
			isFirstClick = false;
		}

		glfwGetCursorPos(window, &endPos->x, &endPos->y);
		offsetPos->x = endPos->x - startPos->x;
		offsetPos->y = startPos->y - endPos->y;

		startPos[0] = endPos[0];
		startPos[1] = endPos[1];

		Point::multiplyBy(offsetPos, sensitivity);

		alpha += offsetPos->x;
		beta += offsetPos->y;

		if (beta > 89.9f)
			beta = 89.9f;
		if (beta < -89.9f)
			beta = -89.9f;

		target.x = sin(glm::radians(alpha)) * cos(glm::radians(beta));
		target.y = sin(glm::radians(beta));
		target.z = cos(glm::radians(alpha)) * -cos(glm::radians(beta));
		target = glm::normalize(target);

		updateFlashlight();
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
	{
		isFirstClick = true;
	}
}

glm::vec3 Camera::getPosition()
{
	return this->eye;
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
	if (prevPosition != eye || prevTarget != target)
	{
		prevPosition = eye;
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
	this->viewMatrix = glm::lookAt(eye, eye + target, up);
}

void Camera::computeProjectionMatrix() {

	this->projectionMatrix = glm::perspective(glm::radians(fov), ratio, near, far);
}

void Camera::setFlashlight(SpotLight* sl) {
	this->flashlight = sl;
}

void Camera::updateFlashlight() {
	if (flashlight) {
		flashlight->updateDirection(this->getDirection());
		flashlight->updatePosition(this->getPosition());
		flashlight->notifyAll(LIGHT);
	}
}

void Camera::notifyAll(int message) {
	for (auto o : observers) {
		o->update(message);
	}
}


