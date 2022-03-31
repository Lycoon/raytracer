#pragma once

#include "../../math/include/vector3.hh"
#include "color.hh"

class Light
{
public:
    Light(Vector3 pos, Color color, float intensity)
        : pos_(pos)
        , color_(color)
        , intensity_(intensity)
    {}

    const Vector3 &getPosition() const;
    const Color &getColor() const;
    float getIntensity() const;

protected:
    Vector3 pos_;
    Color color_;
    float intensity_;
};