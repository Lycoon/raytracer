#pragma once

#include <vector>

#include "../../math/include/point3.hh"

class Blob
{
public:
    Blob(vector<Point3> points, float areaLength, float padding, float level)
        : points_(points)
        , areaLength_(areaLength)
        , padding_(padding)
        , level_(level)
    {}

private:
    vector<Point3> points_;
    float areaLength_;
    float padding_;
    float level_;
};