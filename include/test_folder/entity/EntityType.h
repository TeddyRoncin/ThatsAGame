#pragma once

#include <iostream>

#define BIT(x) (1 << x)

enum class EntityType {
    Entity = BIT(0),
    Renderable = BIT(1)
};

std::ostream& operator<<(std::ostream& out, EntityType type)
{
    switch (type)
    {
    default:
    case EntityType::None:
        out << "EmptyEntity";
        break;

    case EntityType::Entity:
        out << "Simple Entity !\n";
        break;
    }
}
