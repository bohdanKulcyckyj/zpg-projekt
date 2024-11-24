#version 400
//atribut 0 in VAO 
layout(location = 0) in vec3 vp; // position 
//atribut 1 in VAO 
layout(location = 1) in vec3 vn; // normal 

out vec4 worldFragmentPosition;
out vec3 worldNormal;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main(void) {
    worldFragmentPosition = modelMatrix * vec4(vp, 1.0);

    mat4 normalMatrix = transpose(inverse(modelMatrix));
    worldNormal = vec3(normalMatrix * vec4(vn, 0.0));

    gl_Position = projectionMatrix * viewMatrix * worldFragmentPosition;
}