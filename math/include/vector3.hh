#pragma once

#include <cmath>
#include <ostream>

#include "point3.hh"

class Vector3
{
public:
    Vector3(Point3 position)
        : pos_(position){};
    Vector3()
        : pos_()
    {}
    Vector3(float x, float y, float z)
        : pos_(Point3(x, y, z)){};

    Vector3 cross(const Vector3 &v) const;
    float dot(const Vector3 &v) const;
    float magnitude() const;
    void normalize();
    Vector3 rotate(Vector3 axis, float angle);

    void setPosition(Point3 newPos);
    Point3 getPosition() const;
    Vector3 operator+(const Vector3 &v) const;
    Vector3 operator-(const Vector3 &v) const;
    Vector3 operator*(const Vector3 &v) const;
    Vector3 operator/(const Vector3 &v) const;

    Vector3 operator+(const float &l) const;
    Vector3 operator-(const float &l) const;
    Vector3 operator*(const float &l) const;
    Vector3 operator/(const float &l) const;

private:
    Point3 pos_;
};

ostream &operator<<(ostream &out, Vector3 &vect3);