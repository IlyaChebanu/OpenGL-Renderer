#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include "Shader.h"
#include <string>
#include <vector>
#include <iostream>

struct Vertex
{
	glm::vec3 pos;
	glm::vec3 normal;
	glm::vec2 texCoord;
};

struct Texture
{
	unsigned int id;
	std::string type;
	std::string path;
};

class Mesh
{
public:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);

	void Draw(Shader shader);
	void Destroy();

private:
	void InitMesh();

	GLuint VAO, VBO, EBO;
};

