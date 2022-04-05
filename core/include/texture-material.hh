#pragma once

#include <vector>

#include "../../math/include/vector3.hh"
#include "color.hh"

class Material
{
public:
    Material(float kd, float ks, float ka)
        : kd_(kd), ks_(ks), ka_(ka)
    {
    }

    float getKd() const;
    float getKs() const;
    float getKa() const;

private:
    float kd_, ks_, ka_;
};

class TextureMaterial
{
public:
    TextureMaterial(Color *color, Material *material)
        : color_(color), material_(material)
    {
    }

    Material getMaterial(Vector3 p) const;
    virtual Color &getColor(Vector3 p) const = 0;

protected:
    Color *color_;
    Material *material_;
};