#include "include/turtle.hh"

void Turtle::rotateUp(float angle)
{
    float a = degToRad(angle);
    Vector3 head = head_ * cos(a) + left_ * -sin(a);
    Vector3 left = head_ * sin(a) + left_ * cos(a);

    head_ = head;
    left_ = left;

    head_.normalize();
    left_.normalize();
}

void Turtle::rotateLeft(float angle)
{
    float a = degToRad(angle);
    Vector3 head = head_ = head_ * cos(a) + up_ * sin(a);
    Vector3 up = up_ = head_ * -sin(a) + up_ * cos(a);

    head_ = head;
    up_ = up;

    head_.normalize();
    up_.normalize();
}

void Turtle::rotateHead(float angle)
{
    float a = degToRad(angle);
    Vector3 left = left_ = left_ * cos(a) + up_ * sin(a);
    Vector3 up = up_ = left_ * -sin(a) + up_ * cos(a);

    left_ = left;
    up_ = up;

    left_.normalize();
    up_.normalize();
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