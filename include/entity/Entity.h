#pragma once

class Entity
{
public:
	Entity(const char* name, float x, float y);
	virtual ~Entity();

	virtual void Render(SDL_Renderer* renderer) const;

public:
	const char* m_name;
	Position<float> m_pos;
};
