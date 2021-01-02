#include "pch.h"

#include "map/elements/EmptyMapElement.h"

EmptyMapElement::EmptyMapElement()
{}

EmptyMapElement::~EmptyMapElement()
{}

bool EmptyMapElement::operator()(Entity* entity)
{
    return true;
}
