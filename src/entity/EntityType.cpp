#include "pch.h"

#include "entity/EntityType.h"

std::ostream& operator<<(std::ostream& out, EntityType type)
{
	switch (type)
	{
	default:
	case EntityType::None:
	{
		out << "EmptyEntity";
		break;
	}
	case EntityType::Entity:
	{
		out << "Simple Entity !";
		break;
	}
	case EntityType::MapElement:
	{
		out << "Map Element";
		break;
	}
	}
	return out;
}
