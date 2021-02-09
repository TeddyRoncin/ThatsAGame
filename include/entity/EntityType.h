#pragma once

#include <iostream>

enum class EntityType {
    None,
    Entity,
    MapElement
};

std::ostream& operator<<(std::ostream& out, EntityType type);
