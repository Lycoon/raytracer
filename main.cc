#include <iostream>

#include "graphics/include/sphere.hh"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Raytracer" << endl;

    Sphere sphere(5);
    sphere.getNormal(Point3());

    return 0;
}
