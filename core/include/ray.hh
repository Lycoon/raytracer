#pragma once

#include "../../math/include/vector3.hh"

#include <iostream>

class Ray
{
public:
    Ray(Point3 rayOrigin, Vector3 rayDirection) : rayOrigin_(rayOrigin), rayDirection_(rayDirection) {}

    const Point3 &getOrigin() const;
    const Vector3 &getDirection() const;

private:
    Point3 rayOrigin_;
    Vector3 rayDirection_;
};

ostream &operator<<(ostream &out, Ray &ray);