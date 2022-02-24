#include "include/color.hh"

#include <iostream>

// Print
ostream &operator<<(ostream &out, Color &color)
{
    cout << "Color(r=" << color.getRed() << ", g=" << color.getGreen()
         << ", b=" << color.getBlue() << ")";
}