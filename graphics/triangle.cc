#include "include/triangle.hh"

const vector<Vector3> Triangle::getVertices() const
{
    return vector{*v0_, *v1_, *v2_};
}

float Triangle::doesIntersect(Ray ray)
{
    // Möller–Trumbore implementation
    const float EPSILON = 0.0000001;
    Vector3 edge1 = *v1_ - *v0_;
    Vector3 edge2 = *v2_ - *v0_;
    Vector3 h = *ray.getDirection().cross(edge2);
    float a = edge1.dot(h);

    if (a > -EPSILON && a < EPSILON)
        return false; // ray parallel to triangle

    float f = 1.0f / a;
    Vector3 s = ray.getOrigin() - *v0_;
    float u = f * s.dot(h);

    if (u < 0.0 || u > 1.0)
        return false;

    Vector3 q = *s.cross(edge1);
    float v = f * ray.getDirection().dot(q);
    if (v < 0.0 || u + v > 1.0)
        return false;

    float t = f * edge2.dot(q);
    if (t > EPSILON)
        return t;

    return -1;
}

Vector3 &Triangle::getNormal(Vector3 p)
{
    Vector3 edge1 = *v1_ - *v0_;
    Vector3 edge2 = *v2_ - *v0_;
    Vector3 normal = *edge1.cross(edge2);
    normal.normalize();

    return normal;
}

TextureMaterial *Triangle::getTexture(Vector3 p)
{
    return texture_;
}