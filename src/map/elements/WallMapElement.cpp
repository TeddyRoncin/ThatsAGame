#include "pch.h"

#include "map/elements/WallMapElement.h"

WallMapElement::WallMapElement(Position<float> position)
	:MapElement("assets/textures/wall_map_element.png", position, {1.0f, 1.0f})
{
	MapElement::mapElementType = MapElementType::WallMapElement;
}

WallMapElement::~WallMapElement()
{}

bool WallMapElement::operator()(Entity& entity)
{
	return false;
}
