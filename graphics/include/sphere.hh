#pragma once

#include "../../core/include/scene-object.hh"

#include <cmath>

class Sphere : public SceneObject
{
public:
    Sphere(float radius, Point3 center = Point3(0, 0, 0))
        : center_(center), radius_(radius)
    {
    }

    const Point3 &getCenter() const;
    const float getRadius() const;

    float doesIntersect(Ray ray);
    Vector3 getNormal(Point3 p);
    vector<float> getTexture(Point3 p);

private:
    Point3 center_;
    float radius_;
};

ostream &operator<<(ostream &out, Sphere &sphere);