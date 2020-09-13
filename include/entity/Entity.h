#pragma once

#include "utils/Utils.h"

class Entity
{
public:
	Entity(const char* name, float x, float y);
	virtual ~Entity();
public:
	const char* m_name;
	Position<float> m_pos;
};
