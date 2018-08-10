#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "IEventHandler.h"

class Display
{
public:
	Display(int width, int height, const std::string& title);

	void Clear(float r, float g, float b, float a);
	void Update(IEventHandler& eventHandler);
	bool IsClosed();

	virtual ~Display();

private:
	Display(const Display& other) {};
	Display& operator=(const Display& other) {};

	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
};

