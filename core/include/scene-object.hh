#pragma once

#include "../../graphics/include/uniform-texture.hh"
#include "../../math/include/vector3.hh"
#include "ray.hh"
#include "texture-material.hh"

using namespace std;

class SceneObject
{
public:
    SceneObject(TextureMaterial *texture, string id)
        : texture_(texture), id_(id)
    {
    }

    virtual float doesIntersect(Ray ray) = 0;
    virtual Vector3 getNormal(Point3 p) = 0;
    virtual TextureMaterial *getTexture(Point3 p) = 0;

    string getId()
    {
        return id_;
    }

protected:
    TextureMaterial *texture_;
    string id_;
};