#include "pch.h"

#include "entity/Player.h"

Player::Player(Position<float> position)
	:EventListener(this), MovableEntity("assets/textures/player.png", SpriteSheetInfo{0, 8, 16, 0, {}}.addAnimation("stay", {0, 1}), {position.getX(), position.getY()}, {1.0f, 2.0f}), m_LastPos({-1.0f, -1.0f})
{
	setAnimation("stay");
}

void Player::handle()
{
	switch (m_Action)
	{
		case Action::PlayerUp: UpdateLastPos(), m_Position.position.second -= 0.1f; return;
		case Action::PlayerDown: UpdateLastPos(), m_Position.position.second += 0.1f; return;
		case Action::PlayerLeft: UpdateLastPos(), m_Position.position.first -= 0.1f; return;
		case Action::PlayerRight: UpdateLastPos(), m_Position.position.first += 0.1f; return;
	}
}

void Player::UpdateLastPos()
{
	m_LastPos = (m_LastPos == Position{-1.0f, -1.0f} ? m_Position : m_LastPos);
}

bool Player::operator()(Entity& e)
{
	if(e.GetType() == EntityType::MapElement && !e(*this)) {
		m_Position = m_LastPos;
	}
	return false;
}

void Player::Tick(float dt)
{
	static int time(0);
	time++;
	m_LastPos = {-1.0f, -1.0f};
	if(time > 100) {
		updateTexture();
		time = 0;
	}
}
