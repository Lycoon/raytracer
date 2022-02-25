#pragma once

#include "../../math/include/vector3.hh"
#include "texture-material.hh"
#include "ray.hh"

using namespace std;

class SceneObject
{
public:
    virtual float doesIntersect(Ray ray) = 0;
    virtual Vector3 getNormal(Point3 p) = 0;
    // virtual TextureMaterial getTexture(Point3 p) = 0;

private:
    TextureMaterial texture_;
};