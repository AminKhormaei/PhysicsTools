#pragma once

template <typename T>
class Invert
{
    T value_;
    
    public:
        explicit Invert(T value) : value_(value) {}
    
        operator T() const {return -value_;}
        
};
