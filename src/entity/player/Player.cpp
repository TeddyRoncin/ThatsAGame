#include "pch.h"

#include "entity/player/Player.h"
#include "event/EventTypes.h"

Player::Player(const char* name, float x, float y, float width, float height, const char* sprite)
	:Renderable(name, x, y, width, height, sprite)
{
}

Player::~Player()
{
}

void Player::update(const EventHandler& eventHandler)
{
	if (eventHandler.hasEventTriggered(EventTypes::PLAYER_MOVE_UP)) {
		m_pos.position.second -= 1;
	}
	if (eventHandler.hasEventTriggered(EventTypes::PLAYER_MOVE_DOWN)) {
		m_pos.position.second += 1;
	}
	if (eventHandler.hasEventTriggered(EventTypes::PLAYER_MOVE_LEFT)) {
		m_pos.position.first -= 1;
	}
	if (eventHandler.hasEventTriggered(EventTypes::PLAYER_MOVE_RIGHT)) {
		m_pos.position.first += 1;
	}
}