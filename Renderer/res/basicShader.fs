//#version 120
//
//varying vec2 texCoord0; // Shared between shaders and interpolated
//varying vec3 normal0;
//
//uniform sampler2D diffuse; // Both CPU and GPU have access to uniforms
//
//varying vec3 myColour;
//
//void main()
//{
//	//gl_FragColor = texture2D(diffuse, texCoord0) * clamp(dot(-vec3(0.7,-0.7,1), normal0), 0.1, 1.0);
//}

#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 Normal;

uniform sampler2D texture_diffuse1;

void main()
{    
	FragColor = texture(texture_diffuse1, TexCoords) * clamp(dot(-vec3(0.7,-0.7,1), Normal), 0.1, 1.0);
    //FragColor = texture(texture_diffuse1, TexCoords);
}