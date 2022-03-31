#include "include/light.hh"

const Vector3 Light::getPosition() const
{
    return pos_;
}

float Light::getIntensity() const
{
    return intensity_;
}