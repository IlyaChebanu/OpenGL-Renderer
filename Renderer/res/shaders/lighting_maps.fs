#version 330 core

struct Material {
	sampler2D texture_diffuse1;
	sampler2D texture_specular1;
	int shininess;
};

struct Light {
	vec3 position;
	
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

out vec4 FragColor;

in vec2 TexCoords;
in vec3 Normal;
in vec3 FragPos;

uniform vec3 viewPos;

uniform Material material;
uniform Light light;

void main()
{    
	vec3 diffuseTexture = vec3(texture(material.texture_diffuse1, TexCoords));
	vec3 ambient = light.ambient * diffuseTexture;
	
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(light.position - FragPos);
	float diff = max(dot(norm, lightDir), 0.0); // Gets rid of negative values
	vec3 diffuse = light.diffuse * diff * diffuseTexture;
	
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.texture_specular1, TexCoords));
	
	vec3 result = ambient + diffuse + specular;
	FragColor = vec4(result, 1.0);
}