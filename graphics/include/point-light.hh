#pragma once

#include "../../core/include/light.hh"

class PointLight : public Light
{
public:
    PointLight(Point3 pos)
        : Light(pos)
    {}
};