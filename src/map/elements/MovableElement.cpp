#include "pch.h"

#include "map/elements/MovableElement.h"

MovableElement::MovableElement(const char* path, Position<float> position, Dimension<float> dimension)
	:MovableEntity(path, position, dimension)
{}

MovableElement::~MovableElement()
{
	
}
