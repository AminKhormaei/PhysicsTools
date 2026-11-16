
#pragma once

class Vec2D
{
public:
    float x, y;

    Vec2D(float x, float y) : x(x), y(y) {}

    Vec2D operator-() const
    {
        return Vec2D(-x, -y);
    }
};
