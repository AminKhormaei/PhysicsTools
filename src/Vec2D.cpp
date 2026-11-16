#include "PhysicsTools/Vec2D.h"

Vec2D::Vec2D(float x, float y) : x_(x), y_(y) {}

float Vec2D::GetX() const { return x_; }
float Vec2D::GetY() const { return y_; }