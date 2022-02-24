#pragma once

#include <vector>

#include "../../math/include/point3.hh"

class TextureMaterial
{
public:
    TextureMaterial()
    {}

    // should be pure virtual
    virtual std::vector<float> getPos(Point3 p) const;

private:
};