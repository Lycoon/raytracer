#pragma once

#include "../../math/include/utils.hh"
#include "../../math/include/vector3.hh"
#include "../../graphics/include/sphere.hh"

#include "grammar.hh"
#include "scene.hh"

class Turtle
{
public:
    Turtle(Vector3 position, Vector3 head, Vector3 left, Vector3 up)
        : position_(position), head_(head), left_(left), up_(up)
    {
    }

    Turtle()
        : position_(), head_(1, 0, 0), left_(0, 0, 1), up_(0, 1, 0)
    {
    }

    struct TurtleState
    {
        Vector3 position_;
        Vector3 head_, left_, up_;
    };

    void rotateHead(float angle);
    void rotateLeft(float angle);
    void rotateUp(float angle);
    void moveForward(float distance);
    void execute(Scene *scene, string filename);

    void setState();
    void useState();

    Vector3 &getPosition();
    Vector3 &getHead();
    Vector3 &getLeft();
    Vector3 &getUp();

private:
    Vector3 position_;
    Vector3 head_, left_, up_;
    vector<TurtleState *> states_;
};