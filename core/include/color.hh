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

    const int getRed() const;
    const int getGreen() const;
    const int getBlue() const;

    Color operator+(const float &l) const;
    Color operator-(const float &l) const;
    Color operator*(const float &l) const;
    Color operator/(const float &l) const;

private:
    int r_, g_, b_;
};

ostream &operator<<(ostream &out, Color &color);