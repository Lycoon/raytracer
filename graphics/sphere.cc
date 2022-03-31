#include "include/sphere.hh"

#include "include/uniform-texture.hh"

const Vector3 &Sphere::getCenter() const
{
    return center_;
}

float Sphere::getRadius() const
{
    return radius_;
}

/**
 * @brief Checks whether a ray hits a sphere
 *
 * @param Ray
 * @return distance to the hit, -1 if no intersection found (float)
 */
float Sphere::doesIntersect(Ray ray)
{
    Vector3 oc = ray.getOrigin() - center_;

    float a = ray.getDirection().dot(ray.getDirection());
    float b = 2.0 * oc.dot(ray.getDirection());
    float c = oc.dot(oc) - radius_ * radius_;

    float delta = b * b - 4 * a * c;
    if (delta < 0.0)
        return -1;
    else
    {
        float numerator = -b - sqrt(delta);
        if (numerator > 0.0)
            return numerator / (2.0 * a);

        numerator = -b + sqrt(delta);
        if (numerator > 0.0)
            return numerator / (2.0 * a);

        return -1;
    }
}

Vector3 Sphere::getNormal(Vector3 p)
{
    Vector3 normal = p - center_;
    normal.normalize();

    return normal;
}

TextureMaterial *Sphere::getTexture(Vector3 p)
{
    return texture_;
}

ostream &operator<<(ostream &out, Sphere &sphere)
{
    Vector3 center = sphere.getCenter();

    out << "Sphere(" << endl
        << "  center = " << center << "," << endl
        << "  radius = " << sphere.getRadius() << endl
        << ")";

    return out;
}