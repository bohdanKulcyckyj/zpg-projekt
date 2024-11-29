#version 330
layout(location = 0) in vec3 vp;
layout(location = 1) in vec3 vn;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec4 worldFragmentPosition;
out vec3 worldNormal;

void main() {
    worldFragmentPosition = modelMatrix * vec4(vp, 1.0);
    worldNormal = normalize(mat3(transpose(inverse(modelMatrix))) * vn);
    gl_Position = projectionMatrix * (viewMatrix * worldFragmentPosition);
}