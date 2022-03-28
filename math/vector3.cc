#include "include/vector3.hh"

#include <iostream>

void Vector3::abs()
{
    pos_.abs();
}

Vector3 Vector3::cross(const Vector3 &v) const
{
    Point3 posA = getPosition();
    Point3 posB = v.getPosition();

    float crossX = posA.getY() * posB.getZ() - posA.getZ() * posB.getY();
    float crossY = posA.getZ() * posB.getX() - posA.getX() * posB.getZ();
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

Vector3 Vector3::rotate(Vector3 axis, float angle)
{
    float rad = M_PI * (angle / 180.0);
    axis.normalize();

    Vector3 a = *this * cos(rad);
    Vector3 b = (axis.cross(*this) * sin(rad));
    Vector3 c = axis * (axis.dot(*this)) * (1.0 - cos(rad));

    return a + b + c;
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

Vector3 &Vector3::operator+=(const Vector3 &v)
{
    pos_ += v.pos_;
    return *this;
}

Vector3 &Vector3::operator-=(const Vector3 &v)
{
    pos_ -= v.pos_;
    return *this;
}

Vector3 &Vector3::operator*=(const Vector3 &v)
{
    pos_ *= v.pos_;
    return *this;
}

Vector3 &Vector3::operator/=(const Vector3 &v)
{
    pos_ /= v.pos_;
    return *this;
}

bool Vector3::operator==(const Vector3 &v) const
{
    return pos_.getX() == v.pos_.getX() && pos_.getY() == v.pos_.getY() && pos_.getZ() == v.pos_.getZ();
}

ostream &operator<<(ostream &out, Vector3 &vect3)
{
    Point3 pos = vect3.getPosition();
    return out << "Vect3(" << pos << ")";
}