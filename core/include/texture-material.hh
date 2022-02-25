#pragma once

#include <vector>

#include "../../math/include/point3.hh"

class TextureMaterial
{
public:
    virtual vector<float> getComponents(Point3 p) const = 0;
};