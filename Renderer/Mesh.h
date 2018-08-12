#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include "Shader.h"
#include <string>
#include <vector>
#include <iostream>
//#include "obj_loader.h"

//class Vertex
//{
//public:
//	Vertex(const glm::vec3& pos, const glm::vec2& texCoord, const glm::vec3& normal = glm::vec3(0,0,0))
//	{
//		this->pos = pos;
//		this->texCoord = texCoord;
//		this->normal = normal;
//	}
//
//	inline glm::vec3* GetPos() { return &pos; }
//	inline glm::vec2* GetTexCoord() { return &texCoord; }
//	inline glm::vec3* GetNormal() { return &normal; }
//
//private:
//	glm::vec3 pos;
//	glm::vec2 texCoord;
//	glm::vec3 normal;
//};

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

