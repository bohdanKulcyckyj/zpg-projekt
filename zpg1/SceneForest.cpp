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
	int TREES_COUNT = 10;
	ShaderProgram* tree_shaderProgram = new ShaderProgram(camera, "VertexShaderPhongMultipleLights.glsl", "FragmentShaderPhongMultipleLights.glsl");

	SpotLight* flashlight = lm->addSpotLight(
		camera->getDirection(),
		glm::cos(glm::radians(17.5f)),
		glm::cos(glm::radians(20.0f)),
		1.0f,
		0.2f,
		0.01f,
		glm::vec4(0.6, 0.6, 0.6, 1.0),
		glm::vec4(0.385, 0.647, 0.812, 1.0),
		glm::vec4(1.0, 1.0, 1.0, 1.0),
		camera->getPosition(),
		glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	flashlight->attach(tree_shaderProgram);
	camera->setFlashlight(flashlight);

	lm->addDirectionalLight(
		glm::vec3(0.0f, 0.0f, 0.3f),
		glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
		glm::vec4(0.4f, 0.4f, 0.4f, 1.0f),
		glm::vec4(0.5f, 0.5f, 0.5f, 1.0f),
		glm::vec3(2.0, 2.0, 0),
		glm::vec4(0.0, 1.0, 0.0, 1.0))->attach(tree_shaderProgram);

	lm->addPointLight(
		1.f,
		0.01f,
		0.001f,
		glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
		glm::vec4(0.8f, 0.8f, 0.8f, 1.0f),
		glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
		glm::vec3(-2.0, .5, -4),
		glm::vec4(1.0, 0.0, 0.0, 1.0))->attach(tree_shaderProgram);

	lm->addPointLight(
		1.f,
		0.01f,
		0.001f,
		glm::vec4(0.05f, 0.05f, 0.05f, 1.0f),
		glm::vec4(0.8f, 0.8f, 0.8f, 1.0f),
		glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
		glm::vec3(0, 0, 0),
		glm::vec4(0.0, 0.0, 1.0, 1.0))->attach(tree_shaderProgram);

	TextureManager* tm = new TextureManager();
	tm->addTexture(new TextureCubeMap(
		"posx.jpg", "negx.jpg",
		"posy.jpg", "negy.jpg",
		"posz.jpg", "negz.jpg"
	));
	
	SkyCubeModel* model_skybox = new SkyCubeModel();
	ShaderProgram* shaderProgram_skybox = new ShaderProgram(camera, "VertexShaderSkybox.glsl", "FragmentShaderSkyBox.glsl");
	shaderProgram_skybox->setLightManager(lm);
	DrawableObject* obj_skybox = new DrawableObject(shaderProgram_skybox, model_skybox, new Material(glm::vec4(1.0, 1.0, 1.0, 1.0), glm::vec4(1, 1, 1, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0), 16, glm::vec4(1.0, 1.0, 0.0, 1.0)), tm->getTexture(0));
	this->objects.push_back(obj_skybox);

	TransformComposite* initHouseTran = new TransformComposite();
	initHouseTran->addTransform(new TransformTranslate(glm::vec3(-35, 0, 0)));
	initHouseTran->addTransform(new TransformRotate(30.0f, glm::vec3(0, 1, 0)));


	tm->addTexture(new Texture2D("house.png"));

	this->objects.push_back(
		new DrawableObject(
			new ShaderProgram(camera, "VertexShaderLambert.glsl", "FragmentShaderLambert.glsl"),
			new DynamicModel("model.obj"),
			new Material(),
			tm->getTexture(2)
		)
	);

	TreeModel* tree = new TreeModel();

	tree_shaderProgram->setLightManager(lm);
	for (int i = 0; i < TREES_COUNT; i++) {
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
	}
}