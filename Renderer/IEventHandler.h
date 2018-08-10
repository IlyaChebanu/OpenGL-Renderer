#pragma once

class IEventHandler 
{
public:
	IEventHandler() {}
	virtual ~IEventHandler() {}

	virtual void onKeyDown(unsigned __int32 keycode, bool repeat) {}
	virtual void onKeyUp(unsigned __int32 keycode, bool repeat) {}
	virtual void onMouseDown(unsigned __int8 button, unsigned __int32 clicks) {}
	virtual void onMouseUp(unsigned __int8 button, unsigned __int32 clicks) {}
	virtual void onMouseMove(__int32 mouseX, __int32 mouseY, __int32 deltaX, __int32 deltaY) {}
	virtual void onMouseWheel(__int32 amount) {}

private:
	IEventHandler(const IEventHandler& other) {}
	IEventHandler& operator=(const IEventHandler& other) {}
};