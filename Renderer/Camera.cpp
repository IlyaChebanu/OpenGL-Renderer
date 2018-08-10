#include "stdafx.h"
#include "Camera.h"

void Camera::Rotate(float dX, float dY, InputControl& mouseControl, int wheel)
{
	if (wheel)
		m_radius += wheel * m_speed * 25;
	if (m_radius < 0.0f)
		m_radius = 0.0f;

	if (mouseControl.getAmt() == 1.0f)
	{
		m_rotation.x += dY * m_speed;
		m_rotation.y += dX * m_speed;
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
	m_forward = glm::vec4(0, 0, 1, 1) * rotation;
	m_right = glm::vec4(1, 0, 0, 1) * rotation;
}

void Camera::Move(InputControl& forwardControl, InputControl& strafeControl, InputControl& verticalControl)
{
	m_target += m_forward * m_speed * forwardControl.getAmt();
	m_target += m_right * m_speed * strafeControl.getAmt();
	m_target += m_up * m_speed * verticalControl.getAmt();
}