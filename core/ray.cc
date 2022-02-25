#include "include/ray.hh"

const Point3 &Ray::getOrigin() const
{
    return rayOrigin_;
}

const Vector3 &Ray::getDirection() const
{
    return rayDirection_;
}

ostream &operator<<(ostream &out, Ray &ray)
{
    Point3 rayOrigin = ray.getOrigin();
    Vector3 rayDirection = ray.getDirection();

    out << "Ray(" << endl
        << "  origin = " << rayOrigin << "," << endl
        << "  direction = " << rayDirection << endl
        << ")";

    return out;
}