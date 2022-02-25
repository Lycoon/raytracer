#pragma once

#include "../../math/include/vector3.hh"

#include <iostream>

class Ray
{
public:
    Ray(Point3 rayOrigin, Vector3 rayDirection) : rayOrigin_(rayOrigin), rayDirection_(rayDirection) {}
    Ray() : rayOrigin_(Point3(0, 0, 0)), rayDirection_(Vector3(1, 0, 0)) {}

    const Point3 &getOrigin() const;
    const Vector3 &getDirection() const;

private:
    Point3 rayOrigin_;
    Vector3 rayDirection_;
};

ostream &operator<<(ostream &out, Ray &ray);