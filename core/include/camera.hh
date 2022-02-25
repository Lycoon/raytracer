#pragma once

#include "../../math/include/vector3.hh"

using namespace std;

class Camera
{
public:
    Camera(Point3 center, Point3 direction, Vector3 up, int width, int height,
           float fovX = 90)
        : center_(center)
        , direction_(direction)
        , up_(up)
        , height_(height)
        , width_(width)
        , fovX_(90)
    {
        updateFovY();
    }

    void setFovX(float newFovX);
    void setHeight(int newHeight);
    void setWidth(int newWidth);
    void updateFovY();

    Point3 getCenter() const;
    Point3 getDirection() const;
    Vector3 getUp() const;
    int getWidth() const;
    int getHeight() const;
    float getFovX() const;
    float getFovY() const;
    float getZMin() const;

private:
    Point3 center_, direction_;
    Vector3 up_;
    float fovX_, fovY_, zMin_;
    int width_, height_;
};