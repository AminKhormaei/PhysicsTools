#pragma once

class Vec2D
{
    float x_, y_;
    
    public:
        Vec2D(float, float);
        ~Vec2D();
    
        float get_x() const;
        float get_y() const;
};
