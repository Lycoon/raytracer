#pragma once

#include <cmath>
#include <iostream>
#include <ostream>

using namespace std;

class Vector3
{
public:
    Vector3(float x, float y, float z)
        : x_(x)
        , y_(y)
        , z_(z)
    {}

    Vector3()
        : x_(0)
        , y_(0)
        , z_(0)
    {}

    Vector3 *cross(const Vector3 &v) const;
    float dot(const Vector3 &v) const;
    float magnitude() const;
    void abs();
    void normalize();
    Vector3 rotate(Vector3 axis, float angle);

    void updatePosition(float x, float y, float z);
    float X() const;
    float Y() const;
    float Z() const;

    Vector3 operator+(const Vector3 &v) const;
    Vector3 operator-(const Vector3 &v) const;
    Vector3 operator*(const Vector3 &v) const;
    Vector3 operator/(const Vector3 &v) const;

    Vector3 operator+(const float l);
    Vector3 operator-(const float l);
    Vector3 operator*(const float l);
    Vector3 operator/(const float l);

    Vector3 &operator+=(const Vector3 &v);
    Vector3 &operator-=(const Vector3 &v);
    Vector3 &operator*=(const Vector3 &v);
    Vector3 &operator/=(const Vector3 &v);

    Vector3 &operator+=(const float l);
    Vector3 &operator-=(const float l);
    Vector3 &operator*=(const float l);
    Vector3 &operator/=(const float l);

    bool operator==(const Vector3 &v) const;

private:
    float x_, y_, z_;
};

ostream &operator<<(ostream &out, Vector3 &vect3);