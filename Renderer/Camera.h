#pragma once

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "InputControl.h"
#include "Shader.h"

class Camera
{
public:
	Camera(float fov, float aspect, float zNear, float zFar)
	{
		m_perspective = glm::perspective(fov, aspect, zNear, zFar);
		m_forward = glm::vec3(0, 0, 1);
		m_up = glm::vec3(0, 1, 0);
		m_right = glm::vec3(1, 0, 0);
		m_target = glm::vec3(0, 0, 0);
		m_rotation = glm::vec2(0, 0);
		m_pos = glm::vec3(0, 0, 0);
		m_radius = 5.0f;
		m_lookAt = glm::lookAt(glm::vec3(0, 0, 0), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
		m_lookForward = m_lookAt;
	}

	inline glm::mat4 GetViewProjection()
	{
		return m_perspective * m_lookAt;
	}

	inline glm::vec3 GetPos()
	{
		return m_pos;
	}

	void Rotate(float delta, float mouseX, float mouseY, InputControl& mouseControl, int wheel, float sensitivity);
	void Move(float delta, InputControl& forwardControl, InputControl& strafeControl, InputControl& verticalControl, float speed);

private:
	glm::mat4 m_perspective;
	glm::mat4 m_lookAt;
	glm::mat4 m_lookForward;
	glm::vec3 m_forward;
	glm::vec3 m_up;
	glm::vec3 m_right;
	glm::vec3 m_target;
	glm::vec3 m_pos;
	glm::vec2 m_rotation;
	float m_radius;
};