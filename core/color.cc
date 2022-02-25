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