#include "SceneSpheres.h"

SceneSpheres::SceneSpheres(GLFWwindow* w) : Scene(w) {
}

void SceneSpheres::init() {
    LightManager* lm = new LightManager();
    ShaderProgram* sphere_shaderProgram = new ShaderProgram(camera, "VertexShaderPhongMultipleLights.glsl", "FragmentShaderPhongMultipleLights.glsl");
    SphereModel* sphere_model = new SphereModel();
    lm->addLight(glm::vec3(0.0f, 0.0f, -0.6f), glm::vec4(1.0, 1.0, 1.0, 1.0))->attach(sphere_shaderProgram);
    sphere_shaderProgram->setLightManager(lm);

    // Sphere at the top center
    SphereModel* sphereTop_model = new SphereModel();
    DrawableObject* sphereTop_obj = new DrawableObject(sphere_shaderProgram, sphere_model);
    sphereTop_obj->addTransform(new TransformTranslate(glm::vec3(0.0f, 2.0f, 0.0f)));
    this->objects.push_back(sphereTop_obj);

    // Sphere at the bottom center
    DrawableObject* sphereBottom_obj = new DrawableObject(sphere_shaderProgram, sphere_model);
    sphereBottom_obj->addTransform(new TransformTranslate(glm::vec3(0.0f, -2.0f, 0.0f)));
    this->objects.push_back(sphereBottom_obj);

    // Sphere on the left side
    DrawableObject* sphereLeft_obj = new DrawableObject(sphere_shaderProgram, sphere_model);
    sphereLeft_obj->addTransform(new TransformTranslate(glm::vec3(-2.0f, 0.0f, 0.0f)));
    this->objects.push_back(sphereLeft_obj);

    // Sphere on the right side
    DrawableObject* sphereRight_obj = new DrawableObject(sphere_shaderProgram, sphere_model);
    sphereRight_obj->addTransform(new TransformTranslate(glm::vec3(2.0f, 0.0f, 0.0f)));
    this->objects.push_back(sphereRight_obj);
}
