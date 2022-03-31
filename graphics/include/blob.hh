#pragma once

#include <vector>

#include "../../math/include/Vector3.hh"

class Blob
{
public:
    Blob(vector<Vector3> points, float areaLength, float padding, float level)
        : points_(points)
        , areaLength_(areaLength)
        , padding_(padding)
        , level_(level)
    {}

private:
    vector<Vector3> points_;
    float areaLength_;
    float padding_;
    float level_;
};