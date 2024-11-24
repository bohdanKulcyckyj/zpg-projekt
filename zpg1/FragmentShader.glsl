#version 330

in vec3 inColor;
out vec4 outColor;

void main() {
	outColor = vec4(inColor, 0.0);
}