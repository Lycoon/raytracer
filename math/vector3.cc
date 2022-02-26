#include "include/vector3.hh"

#include <iostream>

Vector3 Vector3::cross(const Vector3 &v) const
{
    Point3 posA = getPosition();
    Point3 posB = v.getPosition();

    float crossX = posA.getY() * posB.getZ() - posA.getZ() * posB.getY();
    float crossY = -posA.getX() * posB.getZ() + posA.getZ() * posB.getX();
    float crossZ = posA.getX() * posB.getY() - posA.getY() * posB.getX();

    return Vector3(crossX, crossY, crossZ);
}

float Vector3::dot(const Vector3 &v) const
{
    Point3 prod = pos_ * v.getPosition();
    return prod.getX() + prod.getY() + prod.getZ();
}

float Vector3::magnitude() const
{
    float x = pos_.getX();
    float y = pos_.getY();
    float z = pos_.getZ();

    return sqrt(x * x + y * y + z * z);
}

void Vector3::normalize()
{
    float mag = magnitude();
    if (mag == 0.0)
        return;

    pos_ = pos_ / mag;
}

void Vector3::setPosition(Point3 newPos)
{
    pos_ = newPos;
}

Point3 Vector3::getPosition() const
{
    return pos_;
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

Vector3 Vector3::operator/(const Vector3 &v) const
{
    return Vector3(pos_ / v.getPosition());
}

ostream &operator<<(ostream &out, Vector3 &vect3)
{
    Point3 pos = vect3.getPosition();
    return out << "Vect3(" << pos << ")";
}