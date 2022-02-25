#pragma once

#include "../../math/include/point3.hh"

class Light
{
public:
    Light(Point3 pos)
        : pos_(pos)
    {}

protected:
    Point3 pos_;
};