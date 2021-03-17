#pragma once

struct CollisionBox
{
public:
	const float m_X;
	const float m_Y;
	const float m_Width;
	const float m_Height;

public:
	CollisionBox(float x, float y, float width, float height);
public:
	bool doesCollide(CollisionBox& other) const;
	bool doesCollide(float x, float y) const;
};