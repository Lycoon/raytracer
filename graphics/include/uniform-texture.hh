#pragma once

#include "../../core/include/texture-material.hh"

class UniformTexture : public TextureMaterial
{
public:
    vector<float> getComponents(Point3 p) const;

private:
};