#include "event/EventListener.h"
#include "map/elements/MovableElement.h"

class Player : public EventListener, public MovableElement
{
public:
    Player(Position<float> position);
    virtual void handle();
    virtual bool operator()(Entity& entity) override;
private:
    Position<float> m_LastPos;
};
