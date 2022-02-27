#pragma once

#include "../../math/include/point3.hh"

class Light
{
public:
    Light(Point3 pos, float intensity)
        : pos_(pos)
        , intensity_(intensity)
    {}

    const Point3 getPosition() const;
    float getIntensity() const;

protected:
    Point3 pos_;
    float intensity_;
};