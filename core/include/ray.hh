#pragma once

#include <iostream>

#include "../../math/include/vector3.hh"

class Ray
{
public:
    Ray(Vector3 rayOrigin, Vector3 rayDirection)
        : rayOrigin_(rayOrigin), rayDirection_(rayDirection)
    {
    }

    Vector3 &getOrigin();
    Vector3 &getDirection();

private:
    Vector3 rayOrigin_;
    Vector3 rayDirection_;
};

ostream &operator<<(ostream &out, Ray &ray);