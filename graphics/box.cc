#include "include/box.hh"

#include <algorithm>

#include "include/uniform-texture.hh"

const Vector3 &Box::getCenter() const
{
    return center_;
}

const Vector3 &Box::getPMin() const
{
    return p_min_;
}

const Vector3 &Box::getPMax() const
{
    return p_max_;
}

/**
 * @brief Checks whether a ray hits a box
 *
 * @param Ray
 * @return distance to the hit, -1 if no intersection found (float)
 */
float Box::doesIntersect(Ray ray)
{
    float rO_x = ray.getOrigin().X();
    float rO_y = ray.getOrigin().Y();
    float rO_z = ray.getOrigin().Z();
    float rDir_x = ray.getDirection().X();
    float rDir_y = ray.getDirection().Y();
    float rDir_z = ray.getDirection().Z();

    float tmin = (p_min_.X() - rO_x) / rDir_x;
    float tmax = (p_max_.X() - rO_x) / rDir_x;

    if (tmin > tmax)
        swap(tmin, tmax);

    float tymin = (p_min_.Y() - rO_y) / rDir_y;
    float tymax = (p_max_.Y() - rO_y) / rDir_y;

    if (tymin > tymax)
        swap(tymin, tymax);

    if ((tmin > tymax) || (tymin > tmax))
        return -1;

    if (tymin > tmin)
        tmin = tymin;

    if (tymax < tmax)
        tmax = tymax;

    float tzmin = (p_min_.Z() - rO_z) / rDir_z;
    float tzmax = (p_max_.Z() - rO_z) / rDir_z;

    if (tzmin > tzmax)
        swap(tzmin, tzmax);

    if ((tmin > tzmax) || (tzmin > tmax))
        return -1;

    if (tzmin > tmin)
        tmin = tzmin;

    if (tzmax < tmax)
        tmax = tzmax;

    return tmin;
}

float sign(float value)
{
    return value < 0 ? -1 : 1;
}

Vector3 Box::getNormal(Vector3 p)
{
    float eps = 0.0001f;
    bool diffX_pMin = fabs(p.X() - p_min_.X()) <= eps;
    bool diffY_pMin = fabs(p.Y() - p_min_.Y()) <= eps;
    bool diffZ_pMin = fabs(p.Z() - p_min_.Z()) <= eps;

    bool diffX_pMax = fabs(p.X() - p_max_.X()) <= eps;
    bool diffY_pMax = fabs(p.Y() - p_max_.Y()) <= eps;
    bool diffZ_pMax = fabs(p.Z() - p_max_.Z()) <= eps;

    if (diffX_pMin)
        return Vector3(p_min_.X() > p_max_.X() ? 1 : -1, 0, 0);
    else if (diffY_pMin)
        return Vector3(0, p_min_.Y() > p_max_.Y() ? 1 : -1, 0);
    else if (diffZ_pMin)
        return Vector3(0, 0, p_min_.Z() > p_max_.Z() ? 1 : -1);
    else if (diffX_pMax)
        return Vector3(p_min_.X() > p_max_.X() ? -1 : 1, 0, 0);
    else if (diffY_pMax)
        return Vector3(0, p_min_.Y() > p_max_.Y() ? -1 : 1, 0);
    return Vector3(0, 0, p_min_.Z() > p_max_.Z() ? -1 : 1);
}

TextureMaterial *Box::getTexture(Vector3 p)
{
    return texture_;
}

ostream &operator<<(ostream &out, Box &box)
{
    Vector3 center = box.getCenter();
    Vector3 p_min = box.getPMin();
    Vector3 p_max = box.getPMax();

    out << "Box(" << endl
        << "  center = " << center << "," << endl
        << "  p_min = " << p_min << endl
        << "  p_max = " << p_max << endl
        << ")";

    return out;
}