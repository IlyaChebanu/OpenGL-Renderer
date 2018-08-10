#version 120

varying vec2 texCoord0; // Shared between shaders and interpolated
varying vec3 normal0;

uniform sampler2D diffuse; // Both CPU and GPU have access to uniforms
void main()
{
	gl_FragColor = texture2D(diffuse, texCoord0) * clamp(dot(-vec3(0.7,-0.7,1), normal0), 0.1, 1.0);
}