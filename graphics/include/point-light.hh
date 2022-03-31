#pragma once

#include "../../core/include/light.hh"

class PointLight : public Light
{
public:
    PointLight(Vector3 pos, float intensity)
        : Light(pos, intensity)
    {}
};