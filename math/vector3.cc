#include "include/vector3.hh"

#include <iostream>

void Vector3::abs()
{
    x_ = fabs(x_);
    y_ = fabs(y_);
    z_ = fabs(z_);
}

Vector3 *Vector3::cross(const Vector3 &v) const
{
    float crossX = y_ * v.Z() - z_ * v.Y();
    float crossY = z_ * v.X() - x_ * v.Z();
    float crossZ = x_ * v.Y() - y_ * v.X();

    return new Vector3(crossX, crossY, crossZ);
}

float Vector3::dot(const Vector3 &v) const
{
    return x_ * v.X() + y_ * v.Y() + z_ * v.Z();
}

float Vector3::magnitude() const
{
    return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

void Vector3::normalize()
{
    float mag = magnitude();
    if (mag == 0.0)
        return;

    *this /= mag;
}

Vector3 Vector3::rotate(Vector3 axis, float angle)
{
    float rad = M_PI * (angle / 180.0);
    axis.normalize();

    Vector3 a = *this * cos(rad);
    Vector3 b = (*axis.cross(*this) * sin(rad));
    Vector3 c = axis * (axis.dot(*this)) * (1.0 - cos(rad));

    return a + b + c;
}

void Vector3::updatePosition(float x, float y, float z)
{
    x_ = x;
    y_ = y;
    z_ = z;
}

float Vector3::X() const
{
    return x_;
}

float Vector3::Y() const
{
    return y_;
}

float Vector3::Z() const
{
    return z_;
}

/**
 * Float operations
 */
Vector3 Vector3::operator+(const float l)
{
    return Vector3(x_ + l, y_ + l, z_ + l);
}

Vector3 Vector3::operator-(const float l)
{
    return Vector3(x_ - l, y_ - l, z_ - l);
}

Vector3 Vector3::operator*(const float l)
{
    return Vector3(x_ * l, y_ * l, z_ * l);
}

Vector3 Vector3::operator/(const float l)
{
    return Vector3(x_ / l, y_ / l, z_ / l);
}

Vector3 &Vector3::operator+=(const float l)
{
    x_ += l;
    y_ += l;
    z_ += l;

    return *this;
}

Vector3 &Vector3::operator-=(const float l)
{
    x_ -= l;
    y_ -= l;
    z_ -= l;

    return *this;
}

Vector3 &Vector3::operator*=(const float l)
{
    x_ *= l;
    y_ *= l;
    z_ *= l;

    return *this;
}

Vector3 &Vector3::operator/=(const float l)
{
    x_ /= l;
    y_ /= l;
    z_ /= l;

    return *this;
}

/**
 * Vector3 operations
 */
Vector3 Vector3::operator+(const Vector3 &v) const
{
    return Vector3(x_ + v.X(), y_ + v.Y(), z_ + v.Z());
}

Vector3 Vector3::operator-(const Vector3 &v) const
{
    return Vector3(x_ - v.X(), y_ - v.Y(), z_ - v.Z());
}

Vector3 Vector3::operator*(const Vector3 &v) const
{
    return Vector3(x_ * v.X(), y_ * v.Y(), z_ * v.Z());
}

Vector3 Vector3::operator/(const Vector3 &v) const
{
    return Vector3(x_ / v.X(), y_ / v.Y(), z_ / v.Z());
}

Vector3 &Vector3::operator+=(const Vector3 &v)
{
    x_ += v.X();
    y_ += v.Y();
    z_ += v.Z();

    return *this;
}

Vector3 &Vector3::operator-=(const Vector3 &v)
{
    x_ -= v.X();
    y_ -= v.Y();
    z_ -= v.Z();

    return *this;
}

Vector3 &Vector3::operator*=(const Vector3 &v)
{
    x_ *= v.X();
    y_ *= v.Y();
    z_ *= v.Z();

    return *this;
}

Vector3 &Vector3::operator/=(const Vector3 &v)
{
    x_ /= v.X();
    y_ /= v.Y();
    z_ /= v.Z();

    return *this;
}

bool Vector3::operator==(const Vector3 &v) const
{
    return x_ == v.X() && y_ == v.Y() && z_ == v.Z();
}

ostream &operator<<(ostream &out, Vector3 &v)
{
    return out << "Vector3{" << v.X() << ", " << v.Y() << ", " << v.Z() << "}";
}