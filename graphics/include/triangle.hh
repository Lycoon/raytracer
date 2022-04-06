#pragma once

#include "../../core/include/scene-object.hh"

class Triangle : public SceneObject
{
public:
    Triangle(Vector3 *v0, Vector3 *v1, Vector3 *v2, UniformTexture *texture)
        : SceneObject(texture, "triangle")
        , v0_(v0)
        , v1_(v1)
        , v2_(v2)
    {}

    float doesIntersect(Ray ray);
    Vector3 getNormal(Vector3 p);
    TextureMaterial *getTexture(Vector3 p);

private:
    Vector3 *v0_, *v1_, *v2_;
};