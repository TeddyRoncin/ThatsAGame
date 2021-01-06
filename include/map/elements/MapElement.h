#pragma once

#include "entity//RenderableEntity.h"

class MapElement : public RenderableEntity
{
protected:
    MapElement(const char* path, Position<float> position, Dimension<float> size);
public:
    virtual ~MapElement();
    void Update() {m_Position.position.first += 0.001f;}
};
