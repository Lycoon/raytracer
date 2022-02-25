#include <iostream>

#include "graphics/include/sphere.hh"
#include "core/include/image.hh"
#include "core/include/scene.hh"

using namespace std;

void test() {
    Sphere sphere(1, Point3(2, 2, 2));
    cout << sphere << "\n\n";

    Point3 rayOrigin(0, 0, 0);
    Vector3 rayDirection(1, 1, 1);
    Ray ray(rayOrigin, rayDirection);

    float dist = sphere.doesIntersect(ray);
    cout << "distance = " << dist << endl;

    Image img(800, 600);
    img.save("raytracer.ppm");
}

int main(int argc, char const *argv[])
{
    cout << "=== RAYTRACER ===\n\n";
    // test();

    Scene scene();

    return 0;
}
