#pragma once

#include "entity/Entity.h"

class Renderable : public Entity
{
public:
	Renderable(const char * name, float x, float y, float width, float height, const char* sprite);
	virtual ~Renderable() override;

public:
	Dimension<float> m_dim;
	const char* m_sprite;
};