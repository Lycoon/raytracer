#pragma once

#include <cmath>

#include "../../core/include/scene-object.hh"
#include "./box.hh"

void recursion(vector<Box> &boxes, unsigned int rec, Vector3 p_min,
               Vector3 p_max, UniformTexture *texture);

class Sponge : public SceneObject
{
public:
    Sponge(unsigned int rec, Vector3 p_min, Vector3 p_max,
           UniformTexture *texture)
        : SceneObject(texture, "Sponge")
    {
        boxes_ = {};
        recursion(boxes_, rec, p_min, p_max, texture);
    }

    float doesIntersect(Ray ray);
    Vector3 &getNormal(Vector3 p);
    TextureMaterial *getTexture(Vector3 p);

private:
    Box *latest_hit_ = nullptr;
    vector<Box> boxes_;
};
