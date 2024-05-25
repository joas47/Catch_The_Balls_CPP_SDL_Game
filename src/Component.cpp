// joas47

#include "Component.h"

// This class can be empty.

namespace engine {

    void Component::draw() const {

    }

    Component::Component(int x, int y, int w, int h) : rect{x, y, w, h} {
    }

    Component::~Component() = default;
}