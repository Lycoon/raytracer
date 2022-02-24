#pragma once

#include <ostream>
#include <vector>

#include "include/color.hh"

using namespace std;

class Image
{
public:
    Image(int width, int height)
        : width_(width)
        , height_(height)
    {
        auto line = vector<Color>(width, Color());
        pixels_ = vector<vector<Color>>(height, line);
    }

    int getWidth() const;
    int getHeight() const;
    vector<vector<Color>> getPixels() const;

    friend ostream &operator<<(ostream &out, Image &image);

private:
    vector<vector<Color>> pixels_;
    int width_, height_;
};