#pragma once

#include "event/EventListener.h"
#include "renderer/texture/Texture.h"

class Player : public EventListener
{
public:
	Player(const char* _directory, float _x, float _y, float _width, float _height);
	virtual ~Player() override {}
public:
	virtual void handle() override;
public:
	void Render(SDL_Renderer* renderer);
private:
	Position<float> pos;
	Dimension<float> dim;
	const char* directory;
private:
	Texture texture;
};
