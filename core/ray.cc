#include "include/ray.hh"

Vector3 &Ray::getOrigin()
{
    return rayOrigin_;
}

Vector3 &Ray::getDirection()
{
    return rayDirection_;
}

ostream &operator<<(ostream &out, Ray &ray)
{
    Vector3 rayOrigin = ray.getOrigin();
    Vector3 rayDirection = ray.getDirection();

    out << "Ray(" << endl
        << "  origin = " << rayOrigin << "," << endl
        << "  direction = " << rayDirection << endl
        << ")";

    return out;
}