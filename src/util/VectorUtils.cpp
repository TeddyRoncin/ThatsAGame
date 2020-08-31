#include <vector>

#include "util/VectorUtils.h"

template<typename T> bool VectorUtils::contains(std::vector<T> vect, T value)
{
    for (int i = 0; i < vect.size(); i++) {
        if (vect[i] == value) {
            return true;
        }
    }
    return false;
}