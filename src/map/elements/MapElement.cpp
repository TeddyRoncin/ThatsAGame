#include "pch.h"

#include "map/elements/MapElement.h"

MapElement::MapElement(const char* path, Position<float> position, Dimension<float> size)
    :RenderableEntity(path, Layer::MapElementEntity, position, size)
{
    this->type = EntityType::MapElement;
}

MapElement::~MapElement()
{}
