#include "pch.h"

#include "entity/npc/Npc.h"

Npc::Npc(const char* name, int x, int y, float width, float height, const char* sprite) :
    Renderable(name, x, y, width, height, sprite)
{

}
