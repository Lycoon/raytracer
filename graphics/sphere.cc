#include "include/sphere.hh"

Point3 Sphere::getCenter() const
{
    return center_;
}

float Sphere::getRadius() const
{
    return radius_;
}

bool Sphere::doesIntersect(Point3 startPoint, Vector3 direction)
{}

Vector3 Sphere::getNormal(Point3 p)
{}

TextureMaterial Sphere::getTexture(Point3 p)
{}