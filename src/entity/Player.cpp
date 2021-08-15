#include "pch.h"

#include "entity/Player.h"

Player::Player(Position<float> position)
	:EventListener(this), 
	MovableEntity("assets/textures/player.png", 
		SpriteSheetInfo{{0}, 8, 16, 0, {}}.addAnimation("idle", 0, {0, 1}).addAnimation("run", 1, {0, 1, 2}),
		{position.getX(), position.getY()}, {0.9f, 1.9f}
	),
	m_LastPos({-1.0f, -1.0f})
{
	setAnimation("idle");
}

void Player::handle()
{
	switch (m_Action)
	{
		case Action::PlayerUp: 		UpdateLastPos(), m_Position.position.second -= 0.1f; return;
		case Action::PlayerDown: 	UpdateLastPos(), m_Position.position.second += 0.1f; return;
		case Action::PlayerLeft: 	UpdateLastPos(), m_Position.position.first  -= 0.1f; return;
		case Action::PlayerRight: 	UpdateLastPos(), m_Position.position.first  += 0.1f; return;
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

	if(EventListener::GetKeyState(SDL_SCANCODE_W) || EventListener::GetKeyState(SDL_SCANCODE_A) ||
	EventListener::GetKeyState(SDL_SCANCODE_S) || EventListener::GetKeyState(SDL_SCANCODE_D)) {
		setAnimation("run");
	} else {
		setAnimation("idle");
	}

	if(time > 20) {
		updateTexture();
		time = 0;
	}
}
