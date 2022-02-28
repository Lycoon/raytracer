#include "include/plane.hh"

const Point3 &Plane::getPosition() const
{
    return position_;
}

float Plane::doesIntersect(Ray ray)
{
    float denom = normal_.dot(ray.getDirection());
    if (denom > 1e-6)
    {
        Vector3 p0l0 = position_ - ray.getOrigin();
        float t = p0l0.dot(normal_) / denom;

        if (t >= 0)
            return t;

        return -1;
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