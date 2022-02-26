#pragma once

#include "../../core/include/light.hh"

class PointLight : public Light
{
public:
    PointLight(Point3 pos, float intensity)
        : Light(pos, intensity)
    {}
};