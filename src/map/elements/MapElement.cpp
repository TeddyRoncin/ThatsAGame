#include "pch.h"

#include "map/elements/MapElement.h"

MapElement::MapElement(char* path, Position<float> position, Dimension<float> size)
    :RenderableEntity(path, position, size, Layer::Background)
{}

MapElement::~MapElement()
{}
