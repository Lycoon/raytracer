#include "include/box.hh"

#include "include/uniform-texture.hh"

#include <algorithm>

const Point3 &Box::getCenter() const
{
    return center_;
}

const Point3 &Box::getPMin() const
{
    return p_min_;
}

const Point3 &Box::getPMax() const
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
    float rO_x = ray.getOrigin().getX();
    float rO_y = ray.getOrigin().getY();
    float rO_z = ray.getOrigin().getZ();
    float rDir_x = ray.getDirection().getPosition().getX();
    float rDir_y = ray.getDirection().getPosition().getY();
    float rDir_z = ray.getDirection().getPosition().getZ();

    float tmin = (p_min_.getX() - rO_x) / rDir_x;
    float tmax = (p_max_.getX() - rO_x) / rDir_x;

    if (tmin > tmax)
        swap(tmin, tmax);

    float tymin = (p_min_.getY() - rO_y) / rDir_y;
    float tymax = (p_max_.getY() - rO_y) / rDir_y;

    if (tymin > tymax)
        swap(tymin, tymax);

    if ((tmin > tymax) || (tymin > tmax))
        return -1;

    if (tymin > tmin)
        tmin = tymin;

    if (tymax < tmax)
        tmax = tymax;

    float tzmin = (p_min_.getZ() - rO_z) / rDir_z;
    float tzmax = (p_max_.getZ() - rO_z) / rDir_z;

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

Vector3 Box::getNormal(Point3 p)
{
    float eps = 0.0001f;
    bool diffX_pMin = fabs(p.getX() - p_min_.getX()) <= eps;
    bool diffY_pMin = fabs(p.getY() - p_min_.getY()) <= eps;
    bool diffZ_pMin = fabs(p.getZ() - p_min_.getZ()) <= eps;

    bool diffX_pMax = fabs(p.getX() - p_max_.getX()) <= eps;
    bool diffY_pMax = fabs(p.getY() - p_max_.getY()) <= eps;
    bool diffZ_pMax = fabs(p.getZ() - p_max_.getZ()) <= eps;

    if (diffX_pMin)
        return Vector3(p_min_.getX() > p_max_.getX() ? 1 : -1, 0, 0);
    else if (diffY_pMin)
        return Vector3(0, p_min_.getY() > p_max_.getY() ? 1 : -1, 0);
    else if (diffZ_pMin)
        return Vector3(0, 0, p_min_.getZ() > p_max_.getZ() ? 1 : -1);
    else if (diffX_pMax)
        return Vector3(p_min_.getX() > p_max_.getX() ? -1 : 1, 0, 0);
    else if (diffY_pMax)
        return Vector3(0, p_min_.getY() > p_max_.getY() ? -1 : 1, 0);
    else if (diffZ_pMax)
        return Vector3(0, 0, p_min_.getZ() > p_max_.getZ() ? -1 : 1);
}

TextureMaterial *Box::getTexture(Point3 p)
{
    return texture_;
}

ostream &operator<<(ostream &out, Box &box)
{
    Point3 center = box.getCenter();
    Point3 p_min = box.getPMin();
    Point3 p_max = box.getPMax();

    out << "Box(" << endl
        << "  center = " << center << "," << endl
        << "  p_min = " << p_min << endl
        << "  p_max = " << p_max << endl
        << ")";

    return out;
}