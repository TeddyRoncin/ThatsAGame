#include "entity/MovableEntity.h"
#include "event/EventListener.h"

class Player : public MovableEntity, EventListener
{
public:
    Player(Position<float> position);
    virtual void handle();

};