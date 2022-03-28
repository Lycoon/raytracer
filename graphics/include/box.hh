#pragma once

#include <cmath>

#include "../../core/include/scene-object.hh"

class Box : public SceneObject
{
public:
    Box(Point3 p_min, Point3 p_max, UniformTexture *texture)
        : SceneObject(texture, "box"), p_min_(p_min), p_max_(p_max)
    {
        center_ = (p_min + p_max) / 2;
        size = Vector3(fabs(p_max.getX() - p_min.getX()), fabs(p_max.getY() - p_min.getY()), fabs(p_max.getZ() - p_min.getZ()));
    }

    const Point3 &getPMin() const;
    const Point3 &getPMax() const;
    const Point3 &getCenter() const;

    float doesIntersect(Ray ray);
    Vector3 getNormal(Point3 p);
    TextureMaterial *getTexture(Point3 p);

private:
    Point3 p_min_, p_max_, center_;
    Vector3 size;
};

ostream &operator<<(ostream &out, Box &box);