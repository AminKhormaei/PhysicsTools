#pragma once

/**
 * @file VecInvert.h
 * @brief A lightweight wrapper that stores a value and yields its negation.
 *
 * @details
 * VecInvert<T> holds a value of type `T` and converts implicitly to `T`
 * by returning the negated value. The stored value is never modified.
 *
 * The constructor is `explicit`, so a conversion must be written on purpose:
 * @code{.cpp}
 * VecInvert<Vec2D> inv(Vec2D(1.0f, 2.0f));
 * @endcode
 *
 * @tparam T The value type. It must support unary `operator-`,
 *           for example `Vec2D` or `Vec3D`, or a built-in arithmetic type.
 *
 * @warning The conversion operator returns a new value by copy. It does not
 *          give a reference to the stored value, so `T& r = inv;` will not compile.
 */
template <typename T>
class VecInvert
{
    /// The stored value. Never changed after construction.
    T value_;

public:
    /**
     * @brief Constructs the wrapper from a value.
     * @param value The value to store. It is copied.
     *
     * @note Marked `explicit` to prevent accidental implicit construction.
     */
    explicit VecInvert(T value) : value_(value)
    {
    }

    /**
     * @brief Implicit conversion to `T`. Returns the negated stored value.
     * @return `-value_`. The stored value is not modified.
     *
     * @code{.cpp}
     * VecInvert<Vec2D> inv(Vec2D(1.0f, -2.0f));
     * Vec2D v = inv;          // v == (-1, 2)
     * @endcode
     *
     * @note Each conversion calls `operator-` on the stored value again.
     *       Nothing is cached.
     */
    operator T() const { return -value_; }
};
