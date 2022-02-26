#pragma once

#include <iostream>

#include "../../math/include/vector3.hh"

using namespace std;

class Camera
{
public:
    Camera(Point3 center, Vector3 forward, Vector3 up, int width, int height,
           float fovX = 90)
        : center_(center)
        , forward_(forward)
        , up_(up)
        , height_(height)
        , width_(width)
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

    Point3 getCenter() const;
    Vector3 getForward() const;
    Vector3 getUp() const;
    Vector3 getRight() const;
    int getWidth() const;
    int getHeight() const;
    float getFovX() const;
    float getFovY() const;
    float getZMin() const;

private:
    Point3 center_;
    Vector3 forward_, up_, right_;
    float fovX_, fovY_, zMin_;
    int width_, height_;
};

ostream &operator<<(ostream &out, Camera &cam);