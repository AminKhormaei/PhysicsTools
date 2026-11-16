#pragma once

template <typename T>
class Invert
{
    T value_;
    
    public:
        Invert(T value);
        ~Invert();
    
        T get() const;
        
};
