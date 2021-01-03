#pragma once

#include "test_folder/entity/RenderableEntity.h"

class MapElement : public RenderableEntity
{
protected:
    MapElement(char* path, Position<float> position, Dimension<float> size);
public:
    virtual ~MapElement();
};
