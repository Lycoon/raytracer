#pragma once

#include <cmath>

#include "../../core/include/scene-object.hh"

class Sphere : public SceneObject
{
public:
    Sphere(float radius, Point3 center, UniformTexture *texture)
        : SceneObject(texture, "sphere"), radius_(radius), center_(center)
    {
    }

    const Point3 &getCenter() const;
    const float getRadius() const;

    float doesIntersect(Ray ray);
    Vector3 getNormal(Point3 p);
    TextureMaterial *getTexture(Point3 p);

private:
    Point3 center_;
    float radius_;
};

ostream &operator<<(ostream &out, Sphere &sphere);