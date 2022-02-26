#pragma once

#include "../../core/include/color.hh"
#include "../../core/include/texture-material.hh"

class UniformTexture : public TextureMaterial
{
public:
    UniformTexture(Color color)
        : TextureMaterial(color)
    {}

    vector<float> getComponents(Point3 p) const;
    Color getColor(Point3 p) const;
};