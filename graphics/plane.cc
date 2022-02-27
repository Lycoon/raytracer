#include "include/plane.hh"

const Point3 &Plane::getPosition() const
{
    return position_;
}

float Plane::doesIntersect(Ray ray)
{
    Vector3 dir = ray.getDirection();
    Vector3 normal = normal_;

    float denom = normal.dot(dir);
    if (denom > 0.000001f)
    {
        Vector3 v = position_ - ray.getOrigin();
        float dot = v.dot(normal);
        float dst = dot / denom;

        if (dst >= 0.0f)
            return dst + 2;
    }
    return -1;
}

Vector3 Plane::getNormal(Point3 p)
{
    return normal_;
}

TextureMaterial *Plane::getTexture(Point3 p)
{
    return texture_;
}