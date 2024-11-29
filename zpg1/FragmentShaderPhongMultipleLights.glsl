#version 330
// in vec4 worldPos;
// in vec3 worldNormal;
in vec4 worldFragmentPosition;
in vec3 worldNormal;

out vec4 out_Color;

#define MAX_LIGHTS 10

struct Lights {
    int type;

    vec3 position;
    vec3 direction;
    vec4 color;

    float cutOff;
    float outerCutOff;

    float constant;
    float linear;
    float quadratic;

    vec4 ambient;
    vec4 diffuse;
    vec4 specular;
};

uniform vec3 cameraPosition;
uniform vec3 cameraDirection;
uniform vec4 amb = vec4(1.0, 1.0, 1.0, 1.0);
uniform vec4 diff = vec4(1.0, 1.0, 1.0, 1.0);
uniform vec4 spec = vec4(1.0, 1.0, 1.0, 1.0);
uniform vec4 modelColor = vec4(0.385, 0.647, 0.812, 1.0);
uniform float powExponent = 32.0;
uniform Lights lights[MAX_LIGHTS];
uniform int lightsCount;

vec4 computeSpotLight(Lights light);
vec4 computePointLight(Lights light);
vec4 computeDirectionalLight(Lights light);
vec4 computeBaseLight(Lights l);

float attenuation(float c, float l, float q, float dist);

void main(void) {
    vec4 result = vec4(0.0f);
    for (int i = 0; i < lightsCount; i++)
    {
        if (lights[i].type == 0) {
            result += computeBaseLight(lights[i]);
        }
        if (lights[i].type == 1) {
            result += computeSpotLight(lights[i]);
        }
        if (lights[i].type == 2) {
            result += computeDirectionalLight(lights[i]);
        }
        if (lights[i].type == 3) {
            result += computePointLight(lights[i]);
        }
    }

    out_Color = modelColor * result;
}
vec4 computeBaseLight(Lights light) {
    vec3 cameraVector = normalize(cameraPosition - worldFragmentPosition.xyz);
    vec3 lightVector = normalize(light.position - worldFragmentPosition.xyz);
    vec3 normal = normalize(worldNormal);

    // ambient
    vec4 ambient = amb * light.color;

    // diffuse
    float diffuseStrength = max(0.0, dot(lightVector, normal));
    vec4 diffuse = diff * light.color * diffuseStrength;

    // specular
    vec3 reflection = normalize(reflect(-lightVector, normal));
    float specularStrength = pow(max(0.0, dot(cameraVector, reflection)), powExponent);
    vec4 specular = spec * specularStrength * light.color;

    return (ambient + diffuse + specular);
}
vec4 computePointLight(Lights light) {
    vec3 lightVector = normalize(light.position - worldFragmentPosition.xyz);
    vec3 cameraVector = normalize(cameraPosition - worldFragmentPosition.xyz);
    vec4 ambient = light.ambient * amb * light.color;

    float diffIntensity = max(dot(lightVector, worldNormal), 0.0);
    vec4 diffuse = light.diffuse * diff * diffIntensity * light.color;

    vec3 reflection = reflect(-lightVector, worldNormal);

    float specularStrength = pow(max(dot(cameraVector, reflection), 0.0), powExponent);
    float dist = length(light.position - worldFragmentPosition.xyz);
    vec4 specular = light.specular * spec * specularStrength * light.color;

    float att = attenuation(light.constant, light.linear, light.quadratic, dist);

    ambient *= att;
    diffuse *= att;
    specular *= att;

    return (ambient + diffuse + specular);
}

vec4 computeDirectionalLight(Lights light) {
    vec3 lightVector = normalize(-light.direction);

    vec4 ambient = light.ambient * amb * light.color;

    float diffIntensity = max(dot(lightVector, worldNormal), 0.0);
    vec4 diffuse = light.diffuse * diff * diffIntensity * light.color;

    vec3 cameraVector = normalize(cameraPosition - vec3(worldFragmentPosition / worldFragmentPosition.w));
    vec3 reflection = reflect(-lightVector, worldNormal);
    float specularStrength = pow(max(dot(cameraVector, reflection), 0.0), powExponent);
    vec4 specular = light.specular * spec * specularStrength;

    return (ambient + diffuse + specular);
}

vec4 computeSpotLight(Lights light) {
    // ambient
    vec4 ambient = light.ambient * amb * light.color;

    vec3 lightVector = normalize(light.position - vec3(worldFragmentPosition / worldFragmentPosition.w));
    float diffIntensity = max(dot(lightVector, worldNormal), 0.0);
    vec4 diffuse = light.diffuse * diff * diffIntensity * light.color;

    // specular
    vec3 cameraVector = normalize(cameraPosition - vec3(worldFragmentPosition / worldFragmentPosition.w));
    vec3 reflection = reflect(-lightVector, worldNormal);

    float specularStrength = pow(max(dot(cameraVector, reflection), 0.0), powExponent);
    vec4 specular = light.specular * specularStrength * spec * light.color;

    // soft edges
    float theta = dot(lightVector, normalize(-light.direction));
    float epsilon = (light.cutOff - light.outerCutOff);
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
    diffuse *= intensity;
    specular *= intensity;

    // attenuation
    float distance = length(light.position - vec3(worldFragmentPosition / worldFragmentPosition.w));
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    return (ambient + diffuse + specular);

}

float attenuation(float c, float l, float q, float dist) {
    float att = 1.0 / (c + l * dist + q * (dist * dist));
    return att;
}