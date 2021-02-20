#include "pch.h"
#include "entity/EntityManager.h"

std::map<int, Entity*> EntityManager::entities;

int EntityManager::GetNewID(Entity* entt)
{
	static int id(0);
	entities[id] = entt;
	id++;
	return id - 1;
}

Entity* EntityManager::GetEntity(int a)
{
	return entities.at(a);
}
