#pragma once

#include "../../math/include/vector3.hh"
#include "ray.hh"
#include "texture-material.hh"
#include "uniform-texture.hh"

using namespace std;

class SceneObject
{
public:
    SceneObject(TextureMaterial *texture, string id)
        : texture_(texture), id_(id)
    {
    }

    virtual float doesIntersect(Ray ray) = 0;
    virtual Vector3 &getNormal(Vector3 p) = 0;
    virtual TextureMaterial *getTexture(Vector3 p) = 0;

    string getId()
    {
        return id_;
    }

protected:
    TextureMaterial *texture_;
    string id_;
};