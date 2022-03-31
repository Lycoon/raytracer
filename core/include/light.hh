#pragma once

#include "../../math/include/vector3.hh"

class Light
{
public:
    Light(Vector3 pos, float intensity)
        : pos_(pos)
        , intensity_(intensity)
    {}

    const Vector3 getPosition() const;
    float getIntensity() const;

protected:
    Vector3 pos_;
    float intensity_;
};