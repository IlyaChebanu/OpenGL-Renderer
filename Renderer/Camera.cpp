#include "stdafx.h"
#include "Camera.h"

void Camera::Rotate(float delta, float dX, float dY, InputControl& mouseControl, int wheel, float sensitivity)
{
	if (wheel)
		m_radius += wheel * 0.2f;
	if (m_radius < 0.0f)
		m_radius = 0.0f;

	if (mouseControl.getAmt() == 1.0f)
	{
		m_rotation.x += dY * sensitivity * delta;
		m_rotation.y += dX * sensitivity * delta;
		if (m_rotation.x < -1.57f)
			m_rotation.x = -1.57f;
		if (m_rotation.x > 1.57f)
			m_rotation.x = 1.57f;
	}

	glm::mat4 rotXMat = glm::rotate(m_rotation.x, glm::vec3(1, 0, 0));
	glm::mat4 rotYMat = glm::rotate(m_rotation.y, glm::vec3(0, 1, 0));
	glm::mat4 rotation = rotXMat * rotYMat;

	m_lookAt = glm::translate(glm::vec3(0, 0, -m_radius)) * rotation * glm::translate(-m_target) * m_lookForward;

	m_up = glm::vec4(0, 1, 0, 1) * rotation;
	m_forward = glm::vec4(0, 0, -1, 1) * rotation;
	m_right = glm::vec4(1, 0, 0, 1) * rotation;
}

void Camera::Move(float delta, InputControl& forwardControl, InputControl& strafeControl, InputControl& verticalControl, float speed)
{
	m_target -= m_forward * speed * forwardControl.getAmt() * delta;
	m_target += m_right * speed * strafeControl.getAmt() * delta;
	m_target += m_up * speed * verticalControl.getAmt() * delta;
}