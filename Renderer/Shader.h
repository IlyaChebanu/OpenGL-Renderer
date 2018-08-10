#pragma once

#include <string>
#include <GL/glew.h>
#include "Transform.h"
#include "Camera.h"

class Shader
{
public:
	Shader(const std::string& fileName);

	void Bind(); // Set the GPU to use our shaders
	void Update(const Transform& transform, Camera& camera); // Update uniforms to some values

	virtual ~Shader();

private:
	static const unsigned int NUM_SHADERS = 2;
	Shader(const Shader& other) {};
	Shader& operator=(const Shader& other) {};

	enum
	{
		TRANSFORM_U,
		VIEW_U,

		NUM_UNIFORMS
	};

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];
};

