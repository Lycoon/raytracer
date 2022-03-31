#pragma once

#include <fstream>
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
        auto line = vector<Color>(width, Color(0, 128, 54));
        pixels_ = vector<vector<Color>>(height, line);
    }

    int getWidth() const;
    int getHeight() const;
    const vector<vector<Color>> &getPixels() const;
    void setPixel(int x, int y, Color color);
    void save(string name) const;

private:
    vector<vector<Color>> pixels_;
    int width_, height_;
};

ostream &operator<<(ostream &out, Image &image);