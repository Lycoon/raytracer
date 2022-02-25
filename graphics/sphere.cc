#include "include/sphere.hh"
#include "include/uniform-texture.hh"

const Point3 &Sphere::getCenter() const
{
    return center_;
}

const float Sphere::getRadius() const
{
    return radius_;
}

/**
 * @brief Checks whether a ray hits a sphere by returning its distance to the hit
 * -1 if no intersection found
 *
 * @param startPoint
 * @param direction
 * @return float
 */
float Sphere::doesIntersect(Point3 startPoint, Vector3 direction)
{
    Vector3 oc = startPoint - center_;

    float a = direction.dot(direction);
    float b = 2.0 * oc.dot(direction);
    float c = oc.dot(oc) - radius_ * radius_;

    float delta = b * b - 4 * a * c;
    if (delta < 0.0)
        return -1.0;
    else
    {
        float numerator = -b - sqrt(delta);
        if (numerator > 0.0)
            return numerator / (2.0 * a);

        numerator = -b + sqrt(delta);
        if (numerator > 0.0)
            return numerator / (2.0 * a);
        else
            return -1;
    }
}

Vector3 Sphere::getNormal(Point3 p)
{
    return Vector3();
}

/*
TextureMaterial Sphere::getTexture(Point3 p)
{
    return TextureMaterial();
}
*/

ostream &operator<<(ostream &out, Sphere &sphere)
{
    Point3 center = sphere.getCenter();

    out << "Sphere(" << endl
        << "  center = " << center << "," << endl
        << "  radius = " << sphere.getRadius() << "," << endl
        << ")";

    return out;
}