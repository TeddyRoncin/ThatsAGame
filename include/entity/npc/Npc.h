#pragma once

#include "entity/Renderable.h"


class Npc : public Renderable
{
public:
    Npc(const char* name, int x, int y, float width, float height, const char* sprite);
    virtual void update() = 0;

};
