#include "include/vector3.hh"

#include <iostream>

Vector3 Vector3::cross(const Vector3 &v) const
{
    Point3 pos1 = getPosition();
    Point3 pos2 = v.getPosition();

    float crossX = pos1.getY() * pos2.getZ() - pos1.getZ() * pos2.getY();
    float crossY = -pos1.getX() * pos2.getZ() + pos1.getZ() * pos2.getX();
    float crossZ = pos1.getX() * pos2.getY() - pos1.getY() * pos2.getX();

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
    float x = pos_.getX();
    float y = pos_.getY();
    float z = pos_.getZ();

    pos_ = Point3(x / mag, y / mag, z / mag);
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
    return out << "Vect3(" << pos << ")\n";
}