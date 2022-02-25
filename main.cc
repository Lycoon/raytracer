#include <iostream>

#include "graphics/include/sphere.hh"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "=== RAYTRACER ===\n\n";

    Sphere sphere(1, Point3(0, 2, 0));
    cout << sphere << "\n\n";

    Point3 rayStart(0, 0, 0);
    Vector3 rayDir(0, 1, 0.2);

    float dist = sphere.doesIntersect(rayStart, rayDir);
    cout << "distance = " << dist << endl;

    return 0;
}
