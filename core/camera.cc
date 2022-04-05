#include "include/camera.hh"

#include <iostream>

// Getters
Vector3 &Camera::getCenter() const
{
    return *center_;
}

Vector3 &Camera::getForward() const
{
    return *forward_;
}

Vector3 &Camera::getUp() const
{
    return *up_;
}

Vector3 &Camera::getRight() const
{
    return *right_;
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
    Vector3 center = cam.getCenter();
    Vector3 forward = cam.getForward();
    Vector3 up = cam.getUp();
    Vector3 right = cam.getRight();
    float fovX = cam.getFovX();
    float fovY = cam.getFovY();
    float zMin = cam.getZMin();

    return out << "Camera(" << endl
               << "  center = " << center << ",\n"
               << "  direction = " << forward << ", \n"
               << "  up = " << up << ", \n"
               << "  right = " << right << ", \n"
               << "  fovX = " << fovX << ", \n"
               << "  fovY = " << fovY << ", \n"
               << "  zMin = " << zMin << endl
               << ")";

    return out;
}