#pragma once

#include "../../core/include/scene-object.hh"

class Sphere : SceneObject
{
public:
    Sphere(float radius, Point3 center = Point3(0, 0, 0))
        : center_(center)
        , radius_(radius)
    {}

    Point3 getCenter() const;
    float getRadius() const;

    bool doesIntersect(Point3 startPoint, Vector3 direction);
    Vector3 getNormal(Point3 p);
    TextureMaterial getTexture(Point3 p);

private:
    Point3 center_;
    float radius_;
};