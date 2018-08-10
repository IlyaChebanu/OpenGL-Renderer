#pragma once

#include "IEventHandler.h"
#include "InputControl.h"
#include <map>
#include <vector>
#include "glm/glm.hpp"

class ViewEventHandler : public IEventHandler
{
public:
	ViewEventHandler() {}
	virtual ~ViewEventHandler() {}

	virtual void onKeyDown(unsigned __int32 keycode, bool repeat);
	virtual void onKeyUp(unsigned __int32 keycode, bool repeat);
	virtual void onMouseDown(unsigned __int8 button, unsigned __int32 clicks);
	virtual void onMouseUp(unsigned __int8 button, unsigned __int32 clicks);
	virtual void onMouseMove(__int32 mouseX, __int32 mouseY, __int32 deltaX, __int32 deltaY);
	virtual void onMouseWheel(__int32 amount);

	void addInputControl(unsigned __int32 keycode, InputControl& inputControl, float weight = 1.0f);
	void addMouseControl(unsigned __int32 mouseButton, InputControl& inputControl, float weight = 1.0f);
	inline glm::vec2 GetMousePos() { return mousePos; }
	inline glm::vec2 GetMouseDelta() { return mouseDelta; }
	inline __int32 GetMouseWheel() { __int32 amt = m_wheel; m_wheel = 0; return amt; }

private:
	ViewEventHandler(const ViewEventHandler& other) {}
	ViewEventHandler& operator=(const ViewEventHandler& other) {}

	void updateInput(unsigned __int32 keycode, float weight, bool isRepeat);

	std::map<unsigned __int32, std::vector<std::pair<float, InputControl&>>> inputs; 
	glm::vec2 mousePos;
	glm::vec2 mouseDelta;
	__int32 m_wheel;
};