#include "include/plane.hh"

const Vector3 &Plane::getPosition() const
{
    return *position_;
}

float Plane::doesIntersect(Ray ray)
{
    float denom = ray.getDirection().dot(*normal_);
    if (denom == 0.0f)
        return -1;

    Vector3 rayHit = *position_ - ray.getOrigin();
    float t = rayHit.dot(*normal_) / denom;

    if (t <= 0.0f)
        return -1;

    return t;
}

Vector3 &Plane::getNormal(Vector3 p)
{
    return *normal_;
}

TextureMaterial *Plane::getTexture(Vector3 p)
{
    return texture_;
}