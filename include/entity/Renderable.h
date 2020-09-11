#pragma once

class Renderable
{
public:
	Renderable(float x, float y, float width, float height, const char* sprite);
	virtual ~Renderable();

	Position<float> m_pos;
	Dimension<float> m_dim;
	const char* sprite;
};
