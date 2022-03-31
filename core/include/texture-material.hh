#pragma once

#include <vector>

#include "../../math/include/vector3.hh"
#include "color.hh"

class Components
{
public:
    Components(float kd, float ks, float ka)
        : kd_(kd)
        , ks_(ks)
        , ka_(ka)
    {}

    const float getKd() const;
    const float getKs() const;
    const float getKa() const;

private:
    float kd_, ks_, ka_;
};

class TextureMaterial
{
public:
    TextureMaterial(Color color, Components components)
        : color_(color)
        , comps_(components)
    {}

    Components getComponents(Vector3 p) const;
    virtual Color getColor(Vector3 p) const = 0;

protected:
    Color color_;
    Components comps_;
};