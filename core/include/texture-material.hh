#pragma once

#include <vector>

#include "../../math/include/point3.hh"
#include "color.hh"

class TextureMaterial
{
public:
    TextureMaterial(Color color)
        : color_(color)
    {}

    virtual vector<float> getComponents(Point3 p) const = 0;
    virtual Color getColor(Point3 p) const = 0;

protected:
    Color color_;
};