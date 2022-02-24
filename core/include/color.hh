#pragma once

#include <ostream>

using namespace std;

class Color
{
public:
    Color(int red, int green, int blue)
        : r_(red)
        , g_(green)
        , b_(blue)
    {}
    Color()
        : r_(0)
        , g_(0)
        , b_(0)
    {}

    int getRed() const;
    int getGreen() const;
    int getBlue() const;

    friend ostream &operator<<(ostream &out, Color &color);

private:
    int r_, g_, b_;
};