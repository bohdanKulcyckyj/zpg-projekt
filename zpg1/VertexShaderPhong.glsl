#version 330

layout(location = 0) in vec3 vp;
layout(location = 1) in vec3 vn;

out vec3 worldFragmentPosition;
out vec3 worldNormal;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main() {
    vec4 position = modelMatrix * vec4(vp, 1.0);
    worldFragmentPosition = position.xyz / position.w;
    worldNormal = normalize(transpose(inverse(mat3(modelMatrix))) * vn);
    gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * vec4(vp, 1.0);
};