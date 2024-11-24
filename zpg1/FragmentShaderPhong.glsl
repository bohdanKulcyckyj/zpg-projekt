#version 330

light
int type
vec3 pos
veæ3 dir

// for cyklus pres svetla

in vec3 worldFragmentPosition;
in vec3 worldNormal;

out vec4 out_Color;

uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform vec3 viewPosition = vec3(0.0, 0.0, 1.0);
uniform vec3 objectColor = vec3(0.385, 0.647, 0.812);
uniform float shininess = 32.0;

void main(void) {
    vec3 lightVector = normalize(lightPosition - worldFragmentPosition);
    vec3 norm = normalize(worldNormal);

    vec4 ambient = vec4(0.1, 0.1, 0.1, 1.0);

    float dot_product = max(dot(lightVector, norm), 0.0);
    vec4 diffuse = dot_product * vec4(lightColor * objectColor, 1.0); // object color jen ??

    vec3 viewDir = normalize(viewPosition - worldFragmentPosition);
    vec3 reflectDir = reflect(-lightVector, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec4 specular = spec * vec4(lightColor * objectColor, 1.0);

    out_Color = ambient + diffuse + specular;
}
