#pragma once

#include "../../core/include/light.hh"

class PointLight : public Light
{
public:
    PointLight(Vector3 *pos, Color *color, float intensity)
        : Light(pos, color, intensity)
    {
    }
};