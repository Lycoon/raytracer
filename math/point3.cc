#include "include/point3.hh"

#include <iostream>

#include "include/vector3.hh"

// Getters
float Point3::getX() const
{
    return x_;
}

float Point3::getY() const
{
    return y_;
}

float Point3::getZ() const
{
    return z_;
}

void Point3::abs()
{
    x_ = fabs(x_);
    y_ = fabs(y_);
    z_ = fabs(z_);
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

Point3 &Point3::operator+=(const Point3 &l)
{
    x_ += l.getX();
    y_ += l.getY();
    z_ += l.getZ();

    return *this;
}

Point3 &Point3::operator-=(const Point3 &l)
{
    x_ -= l.getX();
    y_ -= l.getY();
    z_ -= l.getZ();

    return *this;
}

Point3 &Point3::operator*=(const Point3 &l)
{
    x_ *= l.getX();
    y_ *= l.getY();
    z_ *= l.getZ();

    return *this;
}

Point3 &Point3::operator/=(const Point3 &l)
{
    x_ /= l.getX();
    y_ /= l.getY();
    z_ /= l.getZ();

    return *this;
}

Point3 &Point3::operator+=(const float &l)
{
    x_ += l;
    y_ += l;
    z_ += l;

    return *this;
}

Point3 &Point3::operator-=(const float &l)
{
    x_ -= l;
    y_ -= l;
    z_ -= l;

    return *this;
}

Point3 &Point3::operator*=(const float &l)
{
    x_ *= l;
    y_ *= l;
    z_ *= l;

    return *this;
}

Point3 &Point3::operator/=(const float &l)
{
    x_ /= l;
    y_ /= l;
    z_ /= l;

    return *this;
}

// Print
ostream &operator<<(ostream &out, Point3 &p)
{
    return out << "{" << p.getX() << ", " << p.getY() << ", " << p.getZ()
               << "}";
}