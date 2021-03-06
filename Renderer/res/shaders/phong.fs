#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 Normal;
in vec3 FragPos;

uniform sampler2D texture_diffuse1;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos;

void main()
{    
	float ambientStrength = 0.1;
	vec3 ambient = ambientStrength * lightColor;
	
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);
	
	float diff = max(dot(norm, lightDir), 0.0); // Gets rid of negative values
	vec3 diffuse = diff * lightColor;
	
	float specularStrength = 1;
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(lightDir, norm);
	int shininess = 64;
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
	vec3 specular = specularStrength * spec * lightColor;
	
	vec3 result = ambient + diffuse + specular;
	
	vec4 textureColour = texture(texture_diffuse1, TexCoords);
	if (textureColour != vec4(0.0, 0.0, 0.0, 1.0))
	{
		FragColor = texture(texture_diffuse1, TexCoords) * vec4(result, 1.0);
	}
	else
	{
		FragColor = vec4(1.0, 1.0, 1.0, 1.0);
	}
}