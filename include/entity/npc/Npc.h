#pragma once

#include "entity/Renderable.h"


class Npc : public Renderable
{
public:
    Npc(char* name, int x, int y, int width, int height, char* sprite);
    virtual void update() = 0;

};