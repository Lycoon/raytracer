#include "include/vector3.hh"

#include <iostream>

Point3 Vector3::getPosition() const
{
    return pos_;
}

float Vector3::dot(const Vector3 &v) const
{
    Point3 prod = pos_ * v.getPosition();
    return prod.getX() + prod.getY() + prod.getZ();
}

// Float operations
Vector3 Vector3::operator+(const float &l) const
{
    return Vector3(pos_ + l);
}

Vector3 Vector3::operator-(const float &l) const
{
    return Vector3(pos_ - l);
}

Vector3 Vector3::operator*(const float &l) const
{
    return Vector3(pos_ * l);
}

Vector3 Vector3::operator/(const float &l) const
{
    return Vector3(pos_ / l);
}

// Vector3 operations
Vector3 Vector3::operator+(const Vector3 &v) const
{
    return Vector3(pos_ + v.getPosition());
}

Vector3 Vector3::operator-(const Vector3 &v) const
{
    return Vector3(pos_ - v.getPosition());
}

Vector3 Vector3::operator*(const Vector3 &v) const
{
    return Vector3(pos_ * v.getPosition());
}

Vector3 Vector3::operator*(const Vector3 &v) const
{
    return Vector3(pos_ * v.getPosition());
}

ostream &operator<<(ostream &out, Vector3 &vect3)
{
    Point3 pos = vect3.getPosition();
    cout << "Vect3(" << pos << ")\n";
}