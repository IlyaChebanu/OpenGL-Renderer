#version 330 core

struct Material {
	sampler2D texture_diffuse1;
	sampler2D texture_specular1;
	int shininess;
};

struct Light {
	vec3 position;
	vec3 direction;
	float cutOff;
	float outerCutOff;
	
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	
	float constant;
	float linear;
	float quadratic;
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
	
	vec3 lightDir = normalize(light.position - FragPos);
	
	vec3 ambient = light.ambient * diffuseTexture;
	
	vec3 norm = normalize(Normal);
	float diff = max(dot(norm, lightDir), 0.0); // Gets rid of negative values
	vec3 diffuse = light.diffuse * diff * diffuseTexture;
	
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.texture_specular1, TexCoords));
	
	float theta = dot(lightDir, normalize(-light.direction));
	float epsilon = light.cutOff - light.outerCutOff;
	float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);
	diffuse *= intensity;
	specular *= intensity;
	
	float distance = length(light.position - FragPos);
	float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
	
	//ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;
	
	vec3 result = ambient + diffuse + specular;
	FragColor = vec4(result, 1.0);
}