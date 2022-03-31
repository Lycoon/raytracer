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
    void clamp();

    Color operator+(const float &l) const;
    Color operator-(const float &l) const;
    Color operator*(const float &l) const;
    Color operator/(const float &l) const;

    Color operator+(const Color &c) const;
    Color operator-(const Color &c) const;
    Color operator*(const Color &c) const;
    Color operator/(const Color &c) const;

    Color &operator+=(const float &l);
    Color &operator-=(const float &l);
    Color &operator*=(const float &l);
    Color &operator/=(const float &l);

    Color &operator+=(const Color &c);
    Color &operator-=(const Color &c);
    Color &operator*=(const Color &c);
    Color &operator/=(const Color &c);

private:
    int r_, g_, b_;
};

ostream &operator<<(ostream &out, Color &color);