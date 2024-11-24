#version 400
in vec4 worldFragmentPosition;
in vec3 worldNormal;
out vec4 fragColor;

uniform vec3 lightPosition;
uniform vec3 lightColor;

void main(void) {
    vec3 lightDir = normalize(lightPosition - vec3(worldFragmentPosition));
    float diff = max(dot(normalize(worldNormal), lightDir), 0.0);
    vec4 ambient = vec4(0.1, 0.1, 0.1, 1.0);

    vec4 objectColor = vec4(0.385, 0.647, 0.812, 1.0);
    fragColor = ambient + (diff * objectColor);
}
