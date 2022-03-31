#pragma once

#include <iostream>

#include "../../math/include/vector3.hh"

class Ray
{
public:
    Ray(Vector3 rayOrigin, Vector3 rayDirection)
        : rayOrigin_(rayOrigin)
        , rayDirection_(rayDirection)
    {}

    const Vector3 &getOrigin() const;
    const Vector3 &getDirection() const;

private:
    Vector3 rayOrigin_;
    Vector3 rayDirection_;
};

ostream &operator<<(ostream &out, Ray &ray);