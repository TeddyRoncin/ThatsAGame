#include "pch.h"

#include "entity/player/Player.h"

Player::Player(const char* name, float x, float y, float width, float height, const char* sprite)
	:Renderable(name, x, y, width, height, sprite)
{
}

Player::~Player()
{
}
