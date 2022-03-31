#include "include/light.hh"

const Vector3 &Light::getPosition() const
{
    return pos_;
}

const Color &Light::getColor() const
{
    return color_;
}

float Light::getIntensity() const
{
    return intensity_;
}