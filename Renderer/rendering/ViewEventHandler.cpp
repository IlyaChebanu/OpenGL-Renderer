#include "../stdafx.h"
#include "ViewEventHandler.h"


void ViewEventHandler::onKeyDown(unsigned __int32 keycode, bool repeat)
{
	updateInput(keycode, 1.0f, repeat);
}

void ViewEventHandler::onKeyUp(unsigned __int32 keycode, bool repeat)
{
	updateInput(keycode, -1.0f, repeat);
}

void ViewEventHandler::onMouseDown(unsigned __int8 button, unsigned __int32 clicks)
{
	updateInput(button, 1.0f, false);
}

void ViewEventHandler::onMouseUp(unsigned __int8 button, unsigned __int32 clicks)
{
	updateInput(button, -1.0f, false);
}

void ViewEventHandler::onMouseMove(__int32 mouseX, __int32 mouseY, __int32 deltaX, __int32 deltaY)
{
	mousePos = glm::vec2(mouseX, mouseY);
	mouseDelta = glm::vec2(deltaX, deltaY);
}

void ViewEventHandler::onMouseWheel(__int32 amount)
{
	m_wheel = amount;
}


void ViewEventHandler::addInputControl(unsigned __int32 keycode, InputControl& inputControl, float weight)
{
	inputs[keycode].push_back(std::pair<float, InputControl&>(weight, inputControl));
}

void ViewEventHandler::addMouseControl(unsigned __int32 mouseButton, InputControl& inputControl, float weight)
{
	inputs[mouseButton+1024].push_back(std::pair<float, InputControl&>(weight, inputControl));
}


void ViewEventHandler::updateInput(unsigned __int32 keycode, float weight, bool isRepeat)
{
	if (isRepeat)
		return;

	for (int i = 0; i < inputs[keycode].size(); i++)
	{
		inputs[keycode][i].second.addAmt(inputs[keycode][i].first * weight);
	}
}