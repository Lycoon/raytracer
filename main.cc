#include <iostream>

#include "graphics/include/sphere.hh"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "=== RAYTRACER ===\n\n";

    Sphere sphere(1, Point3(0, 2, 0));
    cout << sphere << "\n\n";

    Point3 rayOrigin(0, 0, 0);
    Vector3 rayDirection(0, 1, 0);
    Ray ray(rayOrigin, rayDirection);

    float dist = sphere.doesIntersect(ray);
    cout << "distance = " << dist << endl;

    return 0;
}
