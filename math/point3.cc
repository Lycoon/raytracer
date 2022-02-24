#include "include/point3.hh"

#include <iostream>

// Getters
float Point3::getX() const
{
    return x_;
}

float Point3::getY() const
{
    return x_;
}

float Point3::getZ() const
{
    return z_;
}

// Float operations
Point3 Point3::operator+(const float &l) const
{
    return Point3(x_ + l, y_ + l, z_ + l);
}

Point3 Point3::operator-(const float &l) const
{
    return Point3(x_ - l, y_ - l, z_ - l);
}

Point3 Point3::operator*(const float &l) const
{
    return Point3(x_ * l, y_ * l, z_ * l);
}

Point3 Point3::operator/(const float &l) const
{
    return Point3(x_ / l, y_ / l, z_ / l);
}

// Point3 operations
Point3 Point3::operator+(const Point3 &p) const
{
    return Point3(x_ + p.getX(), y_ + p.getY(), z_ + p.getZ());
}

Point3 Point3::operator-(const Point3 &p) const
{
    return Point3(x_ - p.getX(), y_ - p.getY(), z_ - p.getZ());
}

Point3 Point3::operator*(const Point3 &p) const
{
    return Point3(x_ * p.getX(), y_ * p.getY(), z_ * p.getZ());
}

Point3 Point3::operator/(const Point3 &p) const
{
    return Point3(x_ / p.getX(), y_ / p.getY(), z_ / p.getZ());
}

// Print
ostream &operator<<(ostream &out, Point3 &p)
{
    return out << "Point3(x=" << p.getX() << ", y=" << p.getY()
               << ", z=" << p.getZ() << ")";
}