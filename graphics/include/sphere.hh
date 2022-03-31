#pragma once

#include <cmath>

#include "../../core/include/scene-object.hh"

class Sphere : public SceneObject
{
public:
    Sphere(float radius, Vector3 center, UniformTexture *texture)
        : SceneObject(texture, "sphere")
        , radius_(radius)
        , center_(center)
    {}

    const Vector3 &getCenter() const;
    const float getRadius() const;

    float doesIntersect(Ray ray);
    Vector3 getNormal(Vector3 p);
    TextureMaterial *getTexture(Vector3 p);

private:
    Vector3 center_;
    float radius_;
};

ostream &operator<<(ostream &out, Sphere &sphere);