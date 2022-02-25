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
    fovY_ = fovX_ / (width_ / height_);
}

// Print
ostream &operator<<(ostream &out, Camera &cam)
{
    /*
    return out << "Camera(" << endl
               << "center=" << cam.getCenter() << ",\n"
               << "direction=" << cam.getDirection() << ", \n"
               << "up=" << cam.getUp() << ", \n"
               << "fovX=" << cam.getFovX() << ", \n"
               << "fovY=" << cam.getFovY() << ", \n"
               << "zMin=" << cam.getZMin() << "\n)";
               */
    return out;
}