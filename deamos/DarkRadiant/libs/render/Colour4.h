#pragma once

#include "math/Vector4.h"
#include <cassert>

/**
 * \brief
 * A Vector4 storing RGBA colour
 *
 * This class provides certain convenience methods for treating a 4-element
 * vector as an RGBA colour, for example, ensuring that the colour values lie
 * within the [0.0, 1.0] range.
 */
class Colour4: public Vector4
{
    bool channelValid(double c) const { return c >= 0.0 && c <= 1.0; }

public:

    /// Default-construct an invalid colour
    Colour4()
    : Vector4(-1, -1, -1, -1)
    {
        assert(!isValid());
    }

    /// Initialise a colour with individual components
    Colour4(float r, float g, float b, float a)
    : Vector4(r, g, b, a)
    { }

    /// Construct a Colour4 from a Vector3 and optional alpha
    Colour4(const Vector3& vec, float alpha = 1.0f)
    : Vector4(vec, alpha)
    { }

    /// Return true if this colour contains valid component values
    bool isValid() const
    {
        return channelValid(x()) && channelValid(y())
            && channelValid(z()) && channelValid(w());
    }

public:

    /// Useful colour constants
    static const Colour4& BLACK()
    {
        static Colour4 black(0.0f, 0.0f, 0.0f, 1.0f);
        return black;
    }

    static const Colour4& WHITE()
    {
        static Colour4 white(1.0f, 1.0f, 1.0f, 1.0f);    
        return white;
    }
};

