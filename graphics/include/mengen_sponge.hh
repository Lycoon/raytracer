#pragma once

#include <cmath>

#include "../../core/include/scene-object.hh"
#include "./box.hh"

void recursion(vector<Box> &boxes, unsigned int rec, Point3 &p_min, Point3 p_max, UniformTexture *texture);

class Sponge : public SceneObject
{
public:
    Sponge(unsigned int rec, Point3 p_min, Point3 p_max, UniformTexture *texture)
        : SceneObject(texture, "Sponge")
    {
        boxes_ = {};
        recursion(boxes_, rec, p_min, p_max, texture);
        std::cout << boxes_.size() << endl;
    }

    float doesIntersect(Ray ray);
    Vector3 getNormal(Point3 p);
    TextureMaterial *getTexture(Point3 p);

private:
    Box *latest_hit_ = nullptr;
    vector<Box> boxes_;
};

ostream &operator<<(ostream &out, Sponge &sponge);
