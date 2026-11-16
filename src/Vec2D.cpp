#include "PhysicsTools/Vec2D.h"

Vec2D::Vec2D(float x, float y) : x(x), y(y) {}

Vec2D Vec2D::operator-() const
{
    return Vec2D(-x, -y);
}
