#pragma once

#include "EventDispatcher.h"

class WindowsInput
{
public:
	WindowsInput();
	~WindowsInput() = default;
	void Update(SDL_Event e);

	std::pair<int, int> getCoord() const;
	std::pair<int, int> getSize() const;

	bool isMouseInside() const;
private:
	Position<int> m_coord;
	Dimension<int> m_size;

	bool isMouseIn;
};

class WindowsEvent : public Event 
{
public:
	WindowsEvent(SDL_Event e);
	virtual ~WindowsEvent() = default;
	SDL_WindowEvent event;
};