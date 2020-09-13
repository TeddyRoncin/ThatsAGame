#pragma once

#include "entity/Renderable.h"

class Player : public Renderable
{
public:
	Player(const char* name, float x, float y, float width, float height, const char* sprite);
	virtual ~Player() override;
};
