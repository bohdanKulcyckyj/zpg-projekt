#include "SceneForest.h"
#include <random>

SceneForest::SceneForest(GLFWwindow* w) : Scene(w) {
}

void SceneForest::init() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> scale_dist(0.5f, 2.0f);
	std::uniform_real_distribution<float> rotate_dist(1.0f, 360.0f);
	std::uniform_real_distribution<float> translate_dist(-5.0f, 5.0f);

	LightManager* lm = new LightManager();
	//lm->addLight(glm::vec3(0.6, 0.6, 0.6), glm::vec4(1.0, 1.0, 0.0, 1.0));
	lm->addSpotLight(
		camera->getDirection(),
		glm::cos(glm::radians(17.5f)),
		glm::cos(glm::radians(20.0f)),
		1.0f,
		0.2f,
		0.01f,
		glm::vec4(0.1, 0.1, 0.1, 1.0),
		glm::vec4(0.385, 0.647, 0.812, 1.0),
		glm::vec4(1.0, 1.0, 1.0, 1.0),
		camera->getPosition(),
		glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

	int TREES_COUNT = 10;
	for (int i = 0; i < TREES_COUNT; i++) {
		ShaderProgram* tree_shaderProgram = new ShaderProgram(camera);
		tree_shaderProgram->loadShader("VertexShaderPhongMultipleLights.glsl", "FragmentShaderPhongMultipleLights.glsl");
		TreeModel* tree = new TreeModel();
		tree_shaderProgram->setLightManager(lm);
		DrawableObject* obj_tree = new DrawableObject(tree_shaderProgram, tree);

		glm::vec3 scale(scale_dist(gen), scale_dist(gen), scale_dist(gen));
		float rotation_angle = rotate_dist(gen);
		glm::vec3 rotation_axis(0.0f, 0.1f, 0.0f);
		glm::vec3 translation(translate_dist(gen), 0.0f, translate_dist(gen));

		obj_tree->addTransform(new TransformScale(scale));
		// obj_tree->addTransform(new TransformRotate(rotation_angle, rotation_axis));
		obj_tree->addTransform(new TransformTranslate(translation));
		obj_tree->addTransform(new TransformRotateDynamic(rotation_angle, rotation_axis, 0.5));

		this->objects.push_back(obj_tree);
		this->camera->attach(tree_shaderProgram);
	}
}