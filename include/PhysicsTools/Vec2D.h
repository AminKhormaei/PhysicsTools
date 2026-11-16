#pragma once

class Vec2D
{
    
    
    public:
        float x, y;
    
        Vec2D(float, float);
        ~Vec2D();
    
        Vec2D operator-() const;
    
        float get_x() const;
        float get_y() const;
};
