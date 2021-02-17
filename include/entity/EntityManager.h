#pragma once

#include "Entity.h"

class EntityManager
{
public:
	static int GetNewID(Entity* entt);
	static Entity* GetEntity(int a);
protected:
	static std::map<int, Entity*> entities;
};
