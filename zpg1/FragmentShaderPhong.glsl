#version 330

in vec3 worldFragmentPosition;
in vec3 worldNormal;

uniform vec4 lightColor;
uniform vec3 lightPosition;
uniform vec3 cameraPosition;
uniform vec3 cameraDirection;

out vec4 out_Color;

void main(void) {
    vec3 cameraVector = normalize(cameraPosition - worldFragmentPosition);
    vec3 lightVector = normalize(lightPosition - worldFragmentPosition);
    vec3 normal = normalize(worldNormal);

    // ambient
    vec3 ambient = vec3(0.1, 0.1, 0.1, 1.0); // * lightColor;

    // diffuse
    float diffuseStrength = max(0.0, dot(lightVector, normal));
    vec3 diffuse = diffuseStrength * lightColor;

    // specular
    vec3 reflection = normalize(reflect(-lightVector, normal));
    float specularStrength = pow(max(0.0, dot(cameraVector, reflection)), 10.0);
    vec3 specular = specularStrength * lightColor;
    
    vec3 modelColor = vec3(0.385, 0.647, 0.812, 1.0);

    out_Color = modelColor * (ambient + diffuse + specular);
}
