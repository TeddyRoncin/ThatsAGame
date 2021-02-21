#include "pch.h"

#include "entity/Player.h"

Player::Player(Position<float> position)
	:EventListener(this), MovableEntity("assets/textures/player.png", {position.getX() + 3, position.getY() + 3}, {0.5f, 1.0f}), m_LastPos(position)
{
}

void Player::handle()
{
	switch (m_Action)
	{
		case Action::PlayerUp: m_LastPos = m_Position, m_Position.position.second -= 0.1f; return;
		case Action::PlayerDown: m_LastPos = m_Position, m_Position.position.second += 0.1f; return;
		case Action::PlayerLeft: m_LastPos = m_Position, m_Position.position.first -= 0.1f; return;
		case Action::PlayerRight: m_LastPos = m_Position, m_Position.position.first += 0.1f; return;
	}
}

bool Player::operator()(Entity& e)
{
	if(e.GetType() == EntityType::MapElement && !e(*this)) {
		m_Position = m_LastPos;
	}
	return false;
}
