#include "include/color.hh"

#include <iostream>

const int Color::getRed() const
{
    return r_;
}

const int Color::getGreen() const
{
    return g_;
}

const int Color::getBlue() const
{
    return b_;
}

// Float operations
Color Color::operator+(const float &l) const
{
    return Color(r_ + l, g_ + l, b_ + l);
}

Color Color::operator-(const float &l) const
{
    return Color(r_ - l, g_ - l, b_ - l);
}

Color Color::operator*(const float &l) const
{
    return Color(r_ * l, g_ * l, b_ * l);
}

Color Color::operator/(const float &l) const
{
    return Color(r_ / l, g_ / l, b_ / l);
}

// Color operations
Color Color::operator+(const Color &c) const
{
    return Color(r_ + c.r_, g_ + c.g_, b_ + c.b_);
}

Color Color::operator-(const Color &c) const
{
    return Color(r_ - c.r_, g_ - c.g_, b_ - c.b_);
}

Color Color::operator*(const Color &c) const
{
    return Color(r_ * c.r_, g_ * c.g_, b_ * c.b_);
}

Color Color::operator/(const Color &c) const
{
    return Color(r_ / c.r_, g_ / c.g_, b_ / c.b_);
}

// Print
ostream &operator<<(ostream &out, Color &color)
{
    out << "Color(" << endl
        << "  r = " << color.getRed() << "," << endl
        << "  g = " << color.getGreen() << "," << endl
        << "  b = " << color.getBlue() << endl
        << ")";

    return out;
}