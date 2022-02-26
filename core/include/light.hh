#pragma once

#include "../../math/include/point3.hh"

class Light
{
public:
    Light(Point3 pos, float intensity)
        : pos_(pos)
        , intensity_(intensity)
    {}

protected:
    Point3 pos_;
    float intensity_;
};