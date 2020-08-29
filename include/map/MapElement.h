#pragma once

class MapElement {

    public:
    MapElement() {}
    virtual bool canEntityMoveOn(Entity entity) = 0;

};