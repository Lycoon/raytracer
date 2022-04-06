#pragma once

#include <cmath>

#include "../../core/include/scene-object.hh"

class Box : public SceneObject
{
public:
    Box(Vector3 *p_min, Vector3 *p_max, UniformTexture *texture)
        : SceneObject(texture, "box")
        , p_min_(p_min)
        , p_max_(p_max)
    {
        auto v = (*p_min + *p_max) / 2;
        center_ = new Vector3(v.X(), v.Y(), v.Z());
    }

    Vector3 &getPMin() const;
    Vector3 &getPMax() const;
    Vector3 &getCenter() const;

    float doesIntersect(Ray ray);
    Vector3 getNormal(Vector3 p);
    TextureMaterial *getTexture(Vector3 p);

private:
    Vector3 *p_min_, *p_max_, *center_;
    Vector3 size;
};

ostream &operator<<(ostream &out, Box &box);