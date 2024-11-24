#version 330

in vec4 ex_worldPosition;    // Pozice vrcholu ve svìtových souøadnicích
in vec3 ex_worldNormal;      // Normálový vektor ve svìtových souøadnicích

out vec4 out_Color;

uniform vec3 lightPosition = vec3(10.0, 10.0, 10.0); // Pozice svìtelného zdroje
uniform vec3 lightColor = vec3(1.0, 1.0, 1.0);       // Barva svìtla (bílá)

// Materiálové vlastnosti
uniform vec3 objectColor = vec3(0.385, 0.647, 0.812); // Barva objektu (modrá)
uniform vec3 ambientColor = vec3(0.1, 0.1, 0.1);      // Ambientní složka (šedá)

void main(void) {
    vec3 lightVector = normalize(lightPosition - vec3(ex_worldPosition));
    vec3 normalizedNormal = normalize(ex_worldNormal);

    vec4 ambient = vec4(ambientColor, 1.0);

    float dot_product = max(dot(lightVector, normalizedNormal), 0.0);
    vec4 diffuse = dot_product * vec4(lightColor * objectColor, 1.0);

    out_Color = ambient + diffuse;
}
