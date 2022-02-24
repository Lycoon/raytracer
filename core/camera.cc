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