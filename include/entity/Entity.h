#pragma once

class Entity
{
public:
	Entity(const char* name, float x, float y);
	virtual ~Entity();

	virtual void Render(SDL_Renderer* renderer, int xEnlargement, int yEnlargement) const;

public:
	const char* m_name;
	Position<float> m_pos;
};
