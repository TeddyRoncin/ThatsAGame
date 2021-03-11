#include "pch.h"

#include "utils/CollisionBox.h"

CollisionBox::CollisionBox(int x, int y, int width, int height)
	:m_X(x), m_Y(y), m_Width(width), m_Height(height)
{
}

bool CollisionBox::doesCollide(CollisionBox& other) const
{
	return ((m_X >= other.m_X && m_X < other.m_X + other.m_Width) || (other.m_X >= m_X && other.m_X < m_X + m_Width)) &&
			((m_Y >= other.m_Y && m_Y < other.m_Y + other.m_Height) || (other.m_Y >= m_Y && other.m_Y < m_Y + m_Height));
}

bool CollisionBox::doesCollide(int x, int y) const
{
	return x >= m_X && x < m_X + m_Width && y >= m_Y && y < m_Y + m_Height;
}