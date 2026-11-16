#include "PhysicsTools/Vec3D.h"

Vec3D::Vec3D(float x, float y, float z) : x(x), y(y), z(z) {}
Vec3D::~Vec3D() = default;

float Vec3D::get_x() const { return x; }
float Vec3D::get_y() const { return y; }
float Vec3D::get_z() const { return z; }

Vec3D Vec3D::operator-() const
{
    return Vec3D(-x, -y, -z);
}
