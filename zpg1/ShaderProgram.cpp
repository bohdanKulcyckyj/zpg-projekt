#include "ShaderProgram.h"
#include <iostream>

ShaderProgram::ShaderProgram(Camera* c, const char* vertexFile, const char* fragmentFile) : ShaderLoader(vertexFile, fragmentFile, &this->shaderProgramID) {
	camera = c;
	camera->attach(this);
}

ShaderProgram::ShaderProgram(Camera* c, LightManager* lm, const char* vertexFile, const char* fragmentFile) : ShaderLoader(vertexFile, fragmentFile, &this->shaderProgramID) {
	camera = c;
	camera->attach(this);
	lightManager = lm;
	use();
	updateLights();
	unuse();
}

void ShaderProgram::setLightManager(LightManager* lm) {
	lightManager = lm;
	use();
	updateLights();
	unuse();
}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(shaderProgramID);
}

void ShaderProgram::use() {
	glUseProgram(shaderProgramID);
}

void ShaderProgram::unuse() {
	glUseProgram(0);
}

void ShaderProgram::update(int message)
{
	use();
	updateLights();
	unuse();

	if (message == VIEWMATRIX)
	{
		use();
		updateUniform("viewMatrix", glm::value_ptr(camera->getViewMatrix()));
		updateUniform("cameraPosition", camera->getPosition());
		updateUniform("cameraDirection", camera->getDirection());
		unuse();

		return;
	}

	if (message == PROJECTIONMATRIX)
	{
		use();
		updateUniform("projectionMatrix", glm::value_ptr(camera->getProjectionMatrix()));
		unuse();

		return;
	}

	if (message == LIGHT && lightManager != nullptr) {
		use();
		updateLights();
		unuse();
	}
}

void ShaderProgram::updateUniform(const char* variable, const GLfloat* value)
{
	GLint location = glGetUniformLocation(shaderProgramID, variable);

	if (location >= 0)
	{
		glUniformMatrix4fv(location, 1, GL_FALSE, value);
		return;
	}

	// throw exception("Invalid uniform location ID");
}

void ShaderProgram::updateUniform(const char* variable, glm::vec3 value)
{
	GLint location = glGetUniformLocation(shaderProgramID, variable);

	if (location >= 0)
	{
		glUniform3f(location, value.x, value.y, value.z);
		return;
	}
	// throw exception("Invalid uniform location ID");
}

void ShaderProgram::updateUniform(const char* variable, glm::vec4 value)
{
	GLint location = glGetUniformLocation(shaderProgramID, variable);

	if (location >= 0)
	{
		glUniform4f(location, value.x, value.y, value.z, value.w);
		return;
	}
	// throw exception("Invalid uniform location ID");
}

void ShaderProgram::updateUniform(const char* variable, float value)
{
	GLint location = glGetUniformLocation(shaderProgramID, variable);

	if (location >= 0)
	{
		glUniform1f(location, value);
		return;
	}
	// throw exception("Invalid uniform location ID");
}

void ShaderProgram::updateUniform(const char* variable, int value)
{
	GLint location = glGetUniformLocation(shaderProgramID, variable);

	if (location >= 0)
	{
		glUniform1i(location, value);
		return;
	}
	// throw exception("Invalid uniform location ID");
}

void ShaderProgram::updateLights()
{
	this->updateUniform("lightsCount", this->lightManager->lightsCount);

	this->updateLight();
	this->updatePointLights();
	this->updateDirectionalLight();
	this->updateSpotLight();
}

void ShaderProgram::updateLight()
{
	for (int i = 0; i < this->lightManager->lightsCount; i++) {
		if (this->lightManager->getLight(i)->getType() == BASELIGHT) {
			Light* l = lightManager->getLight(i);

			std::string position = "lights[" + std::to_string(i) + "].position";
			std::string color = "lights[" + std::to_string(i) + "].color";
			std::string type = "lights[" + std::to_string(i) + "].type";
			this->updateUniform(type.c_str(), BASELIGHT);
			this->updateUniform(position.c_str(), l->getPosition());
			this->updateUniform(color.c_str(), l->getColor());

		}
	}
}

void ShaderProgram::updatePointLights()
{
	for (int i = 0; i < this->lightManager->lightsCount; i++) {
		if (this->lightManager->getLight(i)->getType() == POINTLIGHT)
		{
			Light* bl = dynamic_cast<Light*>(lightManager->getLight(i));
			PointLight* pl = dynamic_cast<PointLight*>(bl);

			std::string position = "lights[" + std::to_string(i) + "].position";
			std::string color = "lights[" + std::to_string(i) + "].color";
			std::string constant = "lights[" + std::to_string(i) + "].constant";
			std::string linear = "lights[" + std::to_string(i) + "].linear";
			std::string quadratic = "lights[" + std::to_string(i) + "].quadratic";
			std::string ambient = "lights[" + std::to_string(i) + "].ambient";
			std::string diffuse = "lights[" + std::to_string(i) + "].diffuse";
			std::string specular = "lights[" + std::to_string(i) + "].specular";
			std::string type = "lights[" + std::to_string(i) + "].type";
			this->updateUniform(type.c_str(), POINTLIGHT);

			this->updateUniform(position.c_str(), pl->getPosition());
			this->updateUniform(color.c_str(), pl->getColor());
			this->updateUniform(constant.c_str(), pl->getConstant());
			this->updateUniform(linear.c_str(), pl->getLinear());
			this->updateUniform(quadratic.c_str(), pl->getQuadratic());
			this->updateUniform(ambient.c_str(), pl->getAmbient());
			this->updateUniform(diffuse.c_str(), pl->getDiffuse());
			this->updateUniform(specular.c_str(), pl->getSpecular());
		}
	}
}

void ShaderProgram::updateDirectionalLight()
{
	for (int i = 0; i < this->lightManager->lightsCount; i++) {
		if (lightManager->getLight(i)->getType() == DIRECTIONALLIGHT) {
			Light* bl = dynamic_cast<Light*>(lightManager->getLight(i));
			DirectionalLight* dl = dynamic_cast<DirectionalLight*>(bl);

			std::string color = "lights[" + std::to_string(i) + "].color";
			std::string dir = "lights[" + std::to_string(i) + "].direction";
			std::string ambient = "lights[" + std::to_string(i) + "].ambisent";
			std::string diffuse = "lights[" + std::to_string(i) + "].diffuse";
			std::string specular = "lights[" + std::to_string(i) + "].specular";
			std::string type = "lights[" + std::to_string(i) + "].type";

			this->updateUniform(type.c_str(), DIRECTIONALLIGHT);
			this->updateUniform(dir.c_str(), dl->getDirection());
			this->updateUniform(color.c_str(), dl->getColor());
			this->updateUniform(ambient.c_str(), dl->getAmbient());
			this->updateUniform(diffuse.c_str(), dl->getDiffuse());
			this->updateUniform(specular.c_str(), dl->getSpecular());
		}
	}
}

void ShaderProgram::updateSpotLight()
{

	for (int i = 0; i < this->lightManager->lightsCount; i++) {
		if (this->lightManager->getLight(i)->getType() == SPOTLIGHT) {
			Light* bl = dynamic_cast<Light*>(lightManager->getLight(i));
			SpotLight* sl = dynamic_cast<SpotLight*>(bl);

			std::string position = "lights[" + std::to_string(i) + "].position";
			std::string color = "lights[" + std::to_string(i) + "].color";
			std::string dir = "lights[" + std::to_string(i) + "].direction";
			std::string cu = "lights[" + std::to_string(i) + "].cutOff";
			std::string ocu = "lights[" + std::to_string(i) + "].outerCutOff";
			std::string constant = "lights[" + std::to_string(i) + "].constant";
			std::string linear = "lights[" + std::to_string(i) + "].linear";
			std::string quadratic = "lights[" + std::to_string(i) + "].quadratic";
			std::string ambient = "lights[" + std::to_string(i) + "].ambisent";
			std::string diffuse = "lights[" + std::to_string(i) + "].diffuse";
			std::string specular = "lights[" + std::to_string(i) + "].specular";

			std::string type = "lights[" + std::to_string(i) + "].type";

			this->updateUniform(type.c_str(), SPOTLIGHT);
			this->updateUniform(position.c_str(), sl->getPosition());
			this->updateUniform(dir.c_str(), sl->getDirection());
			this->updateUniform(color.c_str(), sl->getColor());
			this->updateUniform(cu.c_str(), sl->getCutOff());
			this->updateUniform(ocu.c_str(), sl->getOuterCutOff());
			this->updateUniform(constant.c_str(), sl->getConstant());
			this->updateUniform(linear.c_str(), sl->getLinear());
			this->updateUniform(quadratic.c_str(), sl->getQuadratic());
			this->updateUniform(ambient.c_str(), sl->getAmbient());
			this->updateUniform(diffuse.c_str(), sl->getDiffuse());
			this->updateUniform(specular.c_str(), sl->getSpecular());
		}
	}
}