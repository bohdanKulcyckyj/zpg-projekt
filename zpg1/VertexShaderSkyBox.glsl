#version 450

layout(location = 0) in vec3 vp;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
uniform mat4 modelMatrix;

out vec3 fragmentLocalPosition;

void main() {
    vec4 position = modelMatrix * vec4(vp, 1.0);
    fragmentLocalPosition = position.xyz / position.w;
    gl_Position = (projectionMatrix * mat4(mat3(viewMatrix)) * modelMatrix) * vec4(vp, 1.0);
};