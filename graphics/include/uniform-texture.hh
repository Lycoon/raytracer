#pragma once

#include "../../core/include/texture-material.hh"

class UniformTexture : TextureMaterial
{
public:
    std::vector<float> getPos(Point3 p) const;

private:
};