#include "stdafx.h"
#include <GL/glew.h>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Transform.h"
#include "Camera.h"
#include "ViewEventHandler.h"
#include <iostream>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include "Model.h"

#define WIDTH 800
#define HEIGHT 600
#define get_size(x) sizeof(x) / sizeof(x[0])

int main(int argc, char*argv[])
{
	Display display(WIDTH, HEIGHT, "Hello world");

	unsigned int indices[] = { 0, 1, 2 };
	Model nanosuit("./res/nanosuit/nanosuit.obj");

	Shader shader("./res/basicShader");
	glm::vec3 cameraPos = glm::vec3(0, 0, -4);
	Camera camera(70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);
	Transform transform;

	ViewEventHandler eventHandler;

	InputControl zoom;
	InputControl lateral;
	InputControl vertical;
	InputControl cameraMove;
	InputControl forward;

	eventHandler.addInputControl(Input::MOUSE_MIDDLE_BUTTON, zoom, 1.0f);
	eventHandler.addInputControl(Input::KEY_A, lateral, -1.0f);
	eventHandler.addInputControl(Input::KEY_D, lateral, 1.0f);
	eventHandler.addInputControl(Input::KEY_W, forward, -1.0f);
	eventHandler.addInputControl(Input::KEY_S, forward, 1.0f);
	eventHandler.addInputControl(Input::KEY_LSHIFT, vertical, 1.0f);
	eventHandler.addInputControl(Input::KEY_LCTRL, vertical, -1.0f);
	eventHandler.addInputControl(Input::MOUSE_LEFT_BUTTON, cameraMove, 1.0f);

	float counter = 0.0f;
	float rotX = 0.0f;
	float rotY = 0.0f;
	float lastX = 0.0f;
	float lastY = 0.0f;
	float radius = 4.0f;
	glm::vec3 target = glm::vec3(0, 0, 0);
	glm::mat4 lookAt = glm::lookAt(glm::vec3(0, 0, 0), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));

	unsigned __int64 NOW = SDL_GetPerformanceCounter();
	unsigned __int64 LAST = 0;
	float deltaTime = 0;
	while (!display.IsClosed())
	{
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();

		deltaTime = ((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());

		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

		float speed = 0.05f;
		
		glm::vec2 mousePos = eventHandler.GetMousePos();
		float dX = mousePos.x - lastX;
		float dY = mousePos.y - lastY;
		lastX = mousePos.x;
		lastY = mousePos.y;

		int wheel = eventHandler.GetMouseWheel();
		camera.Rotate(deltaTime, dX, dY, cameraMove, wheel, 0.0005f);
		camera.Move(deltaTime, forward, lateral, vertical, 0.005f);

		shader.Bind();

		glm::mat4 mvp = camera.GetViewProjection();
		shader.setUniformMat4("mvp", mvp);

		nanosuit.Draw(shader);

		display.Update(eventHandler);
		counter += 0.01f;
	}

    return 0;
}

