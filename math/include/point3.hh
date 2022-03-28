#pragma once

#include <ostream>

using namespace std;

class Point3
{
public:
    Point3(float x = 0, float y = 0, float z = 0)
        : x_(x), y_(y), z_(z)
    {
    }

    float getX() const;
    float getY() const;
    float getZ() const;

    void abs();

    Point3 operator+(const Point3 &p) const;
    Point3 operator-(const Point3 &p) const;
    Point3 operator*(const Point3 &p) const;
    Point3 operator/(const Point3 &p) const;

    Point3 operator+(const float &l) const;
    Point3 operator-(const float &l) const;
    Point3 operator*(const float &l) const;
    Point3 operator/(const float &l) const;

    Point3 &operator+=(const Point3 &l);
    Point3 &operator-=(const Point3 &l);
    Point3 &operator*=(const Point3 &l);
    Point3 &operator/=(const Point3 &l);

    Point3 &operator+=(const float &l);
    Point3 &operator-=(const float &l);
    Point3 &operator*=(const float &l);
    Point3 &operator/=(const float &l);

private:
    float x_, y_, z_;
};

ostream &operator<<(ostream &out, Point3 &p);