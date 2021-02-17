#pragma once

#include "map/elements/MapElementType.h"

#include "entity/RenderableEntity.h"

class MapElement : public RenderableEntity
{
protected:
	MapElement(const char* path, Position<float> position, Dimension<float> size);
protected:
	MapElementType mapElementType;
public:
	MapElementType GetMapElementType() const;
	virtual ~MapElement();
};
