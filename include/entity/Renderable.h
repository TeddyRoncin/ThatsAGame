#pragma once

// Je vais surement faire hérité renderable de entity pour lui donner l'atribut de position

class Renderable
{
public:
	Renderable(float x, float y, float width, float height, const char* _sprite);
	virtual ~Renderable();

	Position<float> m_pos;
	Dimension<float> m_dim;
	const char* sprite;
};
