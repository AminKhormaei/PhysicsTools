#include "PhysicsTools\Invert.h"

template <typename T>
Invert<T>::Invert(T value) : value_(value) {}

template <typename T>
Invert<T>::~Invert() {}

template <typename T>
T Invert<T>::get() const { return value_; }
