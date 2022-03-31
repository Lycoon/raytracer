#pragma once

#include "../../math/include/utils.hh"
#include "../../math/include/vector3.hh"

class Turtle
{
public:
    Turtle(Vector3 position, Vector3 head, Vector3 left, Vector3 up)
        : position_(position)
        , head_(head)
        , left_(left)
        , up_(up)
    {}

    Turtle()
        : position_()
        , head_(1, 0, 0)
        , left_(0, 0, 1)
        , up_(0, 1, 0)
    {}

    void rotateHead(float angle);
    void rotateLeft(float angle);
    void rotateUp(float angle);
    void moveForward(float distance);

    Vector3 &getPosition();
    Vector3 &getHead();
    Vector3 &getLeft();
    Vector3 &getUp();

private:
    Vector3 position_;
    Vector3 head_, left_, up_;
};