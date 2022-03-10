#pragma once

#include "../../core/include/scene-object.hh"

class Triangle : public SceneObject
{
public:
    Triangle(Point3 v0, Point3 v1, Point3 v2, UniformTexture *texture)
        : SceneObject(texture)
        , v0_(v0)
        , v1_(v1)
        , v2_(v2)
    {}

    const vector<Point3> getVertices() const;

    float doesIntersect(Ray ray);
    Vector3 getNormal(Point3 p);
    TextureMaterial *getTexture(Point3 p);

private:
    Point3 v0_, v1_, v2_;
};