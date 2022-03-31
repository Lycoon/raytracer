#include "include/turtle.hh"

void Turtle::rotateHead(float angle)
{
    float a = degToRad(angle);
    left_ = left_ * cos(a) + up_ * sin(a);
    up_ = left_ * -sin(a) + up_ * cos(a);

    up_.normalize();
    head_.normalize();
    left_.normalize();
}

void Turtle::rotateLeft(float angle)
{
    float a = degToRad(angle);
    head_ = head_ * cos(a) + up_ * sin(a);
    up_ = head_ * -sin(a) + up_ * cos(a);

    up_.normalize();
    head_.normalize();
    left_.normalize();
}

void Turtle::rotateUp(float angle)
{
    float a = degToRad(angle);
    cout << "a: " << a << endl;
    head_ = head_ * cos(a) + left_ * -sin(a);
    left_ = head_ * sin(a) + left_ * cos(a);

    up_.normalize();
    head_.normalize();
    left_.normalize();
}

void Turtle::moveForward(float distance)
{
    position_ += head_ * distance;
}

Vector3 &Turtle::getPosition()
{
    return position_;
}

Vector3 &Turtle::getHead()
{
    return head_;
}

Vector3 &Turtle::getLeft()
{
    return left_;
}

Vector3 &Turtle::getUp()
{
    return up_;
}