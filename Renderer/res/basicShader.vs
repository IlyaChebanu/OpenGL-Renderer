//#version 120
//
//attribute vec3 normal;
//attribute vec3 position;
//attribute vec2 texCoord;
//
//varying vec2 texCoord0;
//varying vec3 normal0;
//
//uniform mat4 transform; // Uniform can be set by the CPU
//
//void main()
//{
//	gl_Position = transform * vec4(position, 1.0);
//	texCoord0 = texCoord;
//	normal0 = (transform * vec4(normal, 0.0)).xyz; // 0.0 meaning no translation of the normal
//}

#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;
out vec3 Normal;

uniform mat4 mvp;

void main()
{
	Normal = aNormal;
    TexCoords = aTexCoords;    
    gl_Position = mvp * vec4(aPos, 1.0);
}