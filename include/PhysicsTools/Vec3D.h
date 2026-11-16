
#pragma once

class Vec3D
{
public:
    float x, y, z;

    Vec3D(float x, float y, float z)
        : x(x), y(y), z(z) {}

    Vec3D operator-() const
    {
        return Vec3D(-x, -y, -z);
    }
};
