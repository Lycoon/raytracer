#pragma once

#include <ostream>
#include <vector>

#include "include/color.hh"

using namespace std;

class Image
{
public:
    Image(int width, int height)
        : width_(width), height_(height)
    {
        auto line = vector<Color>(width, Color());
        pixels_ = vector<vector<Color>>(height, line);
    }

    const int getWidth() const;
    const int getHeight() const;
    const vector<vector<Color>> &getPixels() const;

private:
    vector<vector<Color>> pixels_;
    int width_, height_;
};

ostream &operator<<(ostream &out, Image &image);