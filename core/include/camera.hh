#pragma once

#include <iostream>

#include "../../math/include/vector3.hh"

using namespace std;

class Camera
{
public:
    Camera(Vector3 center, Vector3 forward, Vector3 up, int width, int height,
           float fovX = 90)
        : center_(center)
        , forward_(forward)
        , up_(up)
        , width_(width)
        , height_(height)
        , fovX_(fovX)
        , zMin_(0)
    {
        updateFovY();

        up_.normalize();
        forward_.normalize();
        right_ = up_.cross(forward_);
    }

    void setFovX(float newFovX);
    void setHeight(int newHeight);
    void setWidth(int newWidth);
    void updateFovY();

    Vector3 getCenter() const;
    Vector3 getForward() const;
    Vector3 getUp() const;
    Vector3 getRight() const;
    int getWidth() const;
    int getHeight() const;
    float getFovX() const;
    float getFovY() const;
    float getZMin() const;

private:
    Vector3 center_, forward_, up_, right_;
    float fovX_, zMin_, fovY_;
    int width_, height_;
};

ostream &operator<<(ostream &out, Camera &cam);