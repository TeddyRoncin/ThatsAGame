#pragma once

#include "entity/Renderable.h"
<<<<<<< HEAD
#include "entity/npc/ai/PathFinder.h"
=======
>>>>>>> github/functionnal


class Npc : public Renderable
{
public:
    Npc(const char* name, float x, float y, float width, float height, const char* sprite);
    virtual void update() = 0;

};
