#include "PhysicsTools/Vec2D.h"

Vec2D::Vec2D(float x, float y) : x_(x), y_(y) {}
Vec2D::~Vec2D() = default;


float Vec2D::get_x() const { return x_; }
float Vec2D::get_y() const { return y_; }

