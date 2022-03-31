#pragma once

#include "../../core/include/color.hh"
#include "../../core/include/texture-material.hh"

class UniformTexture : public TextureMaterial
{
public:
    UniformTexture(Color color, Components components)
        : TextureMaterial(color, components)
    {}

    Color getColor(Vector3 p) const;
};