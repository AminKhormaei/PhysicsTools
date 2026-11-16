#include "PhysicsTools/Vec3D.h"

Vec3D::Vec3D(float x, float y, float z) : x_(x), y_(y), z_(z) {}
Vec3D::~Vec3D() = default;

float Vec3D::get_x() const { return x_; }
float Vec3D::get_y() const { return y_; }
float Vec3D::get_z() const { return z_; }
