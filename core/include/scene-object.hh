#pragma once

#include "../../math/include/vector3.hh"
#include "texture-material.hh"

using namespace std;

class SceneObject
{
public:
    SceneObject()
    {
    }

    virtual float doesIntersect(Point3 startPoint, Vector3 direction) = 0;
    virtual Vector3 getNormal(Point3 p) = 0;
    // virtual TextureMaterial getTexture(Point3 p) = 0;

private:
    TextureMaterial texture_;
};