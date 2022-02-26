#include "include/camera.hh"

#include <iostream>

// Getters
Point3 Camera::getCenter() const
{
    return center_;
}

Point3 Camera::getDirection() const
{
    return direction_;
}

Vector3 Camera::getUp() const
{
    return up_;
}

int Camera::getWidth() const
{
    return width_;
}

int Camera::getHeight() const
{
    return height_;
}

float Camera::getFovX() const
{
    return fovX_;
}

float Camera::getFovY() const
{
    return fovY_;
}

float Camera::getZMin() const
{
    return zMin_;
}

// Setters
void Camera::setFovX(float newFovX)
{
    fovX_ = newFovX;
    updateFovY();
}

void Camera::setHeight(int newHeight)
{
    height_ = newHeight;
    updateFovY();
}

void Camera::setWidth(int newWidth)
{
    width_ = newWidth;
    updateFovY();
}

void Camera::updateFovY()
{
    fovY_ = fovX_ / ((float)width_ / (float)height_);
}

// Print
ostream &operator<<(ostream &out, Camera &cam)
{
    Point3 center = cam.getCenter();
    Point3 direction = cam.getDirection();
    Vector3 up = cam.getUp();
    float fovX = cam.getFovX();
    float fovY = cam.getFovY();
    float zMin = cam.getZMin();

    return out << "Camera(" << endl
               << "  center = " << center << ",\n"
               << "  direction = " << direction << ", \n"
               << "  up = " << up << ", \n"
               << "  fovX = " << fovX << ", \n"
               << "  fovY = " << fovY << ", \n"
               << "  zMin = " << zMin << endl
               << ")";

    return out;
}